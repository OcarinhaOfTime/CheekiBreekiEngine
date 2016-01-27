#include <GL\glew.h>
#include <Graphics\Mesh.h>
#include <iostream>
#include <glm\glm.hpp>


namespace CheekiBreekiEngine {
	void generateAttrib(GLuint &buffer, GLsizeiptr size, const void* data,
		GLint vapIndex, GLint vapSize, GLenum vapType, GLenum target = GL_ARRAY_BUFFER) {
		glGenBuffers(1, &buffer);
		glBindBuffer(target, buffer);
		glBufferData(target, size, data, GL_STATIC_DRAW);

		glVertexAttribPointer(vapIndex, vapSize, vapType, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(vapIndex);
	}

	Mesh::MeshEntry::MeshEntry(aiMesh *mesh) {
		vbo[VERTEX_BUFFER] = NULL;
		vbo[TEXCOORD_BUFFER] = NULL;
		vbo[NORMAL_BUFFER] = NULL;
		vbo[INDEX_BUFFER] = NULL;

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		elementCount = mesh->mNumFaces * 3;

		if (mesh->HasPositions()) {
			generateAttrib(vbo[VERTEX_BUFFER], 3 * mesh->mNumVertices * sizeof(GLfloat),
				&(mesh->mVertices[0]), 0, 3, GL_FLOAT);
		}

		if (mesh->HasTextureCoords(0)) {
			glm::vec2* mTextureCoords = new glm::vec2[mesh->mNumVertices];
			for (int i = 0; i < mesh->mNumVertices; i++) {
				mTextureCoords[i].x = mesh->mTextureCoords[0][i].x;
				mTextureCoords[i].y = 1 - mesh->mTextureCoords[0][i].y;
			}
			generateAttrib(vbo[TEXCOORD_BUFFER], 2 * mesh->mNumVertices * sizeof(GLfloat),
				&(mTextureCoords[0]), 1, 2, GL_FLOAT);
			delete[] mTextureCoords;
		}
		else {
			std::cout << "some mesh does not have uvs... kek: " << mesh->mNumUVComponents << std::endl;
		}

		if (mesh->HasNormals()) {
			generateAttrib(vbo[NORMAL_BUFFER], 3 * mesh->mNumVertices * sizeof(GLfloat),
				&(mesh->mNormals[0]), 2, 3, GL_FLOAT);
		}


		if (mesh->HasFaces()) {
			unsigned int *indices = new unsigned int[mesh->mNumFaces * 3];
			for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
				indices[i * 3] = mesh->mFaces[i].mIndices[0];
				indices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
				indices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
			}

			generateAttrib(vbo[INDEX_BUFFER], 3 * mesh->mNumFaces * sizeof(GLuint),
				indices, 3, 3, GL_UNSIGNED_INT, GL_ELEMENT_ARRAY_BUFFER);

			delete indices;
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	/**
	*	Deletes the allocated OpenGL buffers
	**/
	Mesh::MeshEntry::~MeshEntry() {
		if (vbo[VERTEX_BUFFER]) {
			glDeleteBuffers(1, &vbo[VERTEX_BUFFER]);
		}

		if (vbo[TEXCOORD_BUFFER]) {
			glDeleteBuffers(1, &vbo[TEXCOORD_BUFFER]);
		}

		if (vbo[NORMAL_BUFFER]) {
			glDeleteBuffers(1, &vbo[NORMAL_BUFFER]);
		}

		if (vbo[INDEX_BUFFER]) {
			glDeleteBuffers(1, &vbo[INDEX_BUFFER]);
		}

		glDeleteVertexArrays(1, &vao);
	}

	/**
	*	Renders this MeshEntry
	**/
	void Mesh::MeshEntry::render() {
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, NULL);
		glBindVertexArray(0);
	}

	/**
	*	Mesh constructor, loads the specified filename if supported by Assimp
	**/
	void Mesh::loadFromFile(std::string filename) {
		Assimp::Importer importer;
		const aiScene *scene = importer.ReadFile(filename, aiProcess_JoinIdenticalVertices | aiProcess_GenNormals | aiProcess_ImproveCacheLocality | aiProcess_Triangulate | aiProcess_GenUVCoords);
		if (!scene) {
			printf("Unable to laod mesh: %s\n", importer.GetErrorString());
		}

		for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
			meshEntries.push_back(new Mesh::MeshEntry(scene->mMeshes[i]));
		}
	}

	/**
	*	Clears all loaded MeshEntries
	**/
	Mesh::~Mesh() {
		for (int i = 0; i < meshEntries.size(); ++i) {
			delete meshEntries.at(i);
		}
		meshEntries.clear();
	}

	/**
	*	Renders all loaded MeshEntries
	**/
	void Mesh::render() {
		for (int i = 0; i < meshEntries.size(); ++i) {
			meshEntries.at(i)->render();
		}
	}
}

