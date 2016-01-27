#include <GL\glew.h>

#include <Graphics\Material.h>
#include <Core\IOUtils.h>

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::pair;

namespace CheekiBreekiEngine {
	GLenum getActiveTexture(unsigned int rank) {
		switch (rank) {
		case 0:
			return GL_TEXTURE0;
		case 1:
			return GL_TEXTURE1;
		case 2:
			return GL_TEXTURE2;
		case 3:
			return GL_TEXTURE3;
		case 4:
			return GL_TEXTURE4;
		default:
			return -1;
		}
	}

	Material::~Material() {}

	void Material::initialise(Shader* shader) {
		programID = shader->programID;
		mvpID = glGetUniformLocation(programID, "MVP");
	}

	void Material::setMatrixUniform(const char* uniformName, glm::mat4 & mtx) {
		GLuint uniformID = glGetUniformLocation(programID, uniformName);
		glUniformMatrix4fv(uniformID, 1, GL_FALSE, &mtx[0][0]);
	}

	void Material::setMVP(glm::mat4 & MVP) {
		glUniformMatrix4fv(mvpID, 1, GL_FALSE, &MVP[0][0]);
	}

	void Material::setVec3Uniform(const char * uniformName, glm::vec3 & vec) {
		GLuint uniformID = glGetUniformLocation(programID, uniformName);
		glUniform3fv(uniformID, 1, &vec[0]);
	}

	void Material::bindSampler(Sampler2D* sampler) {
		glActiveTexture(sampler->activeTexture);
		sampler->texture->bind();
		glUniform1i(sampler->uniformLocation, sampler->rank);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sampler->textureWrapS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, sampler->textureWrapT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void Material::addSample(string uniformName, Texture * texture) {
		addSample(uniformName, texture, GL_REPEAT, GL_REPEAT);
	}

	void Material::addSample(string uniformName, Texture * texture, unsigned int textureWrapS, unsigned int textureWrapT) {
		Sampler2D* sampler = new Sampler2D;
		sampler->texture = texture;
		sampler->uniformLocation = glGetUniformLocation(programID, uniformName.c_str());
		sampler->textureWrapS = textureWrapS;
		sampler->textureWrapT = textureWrapT;
		sampler->rank = samplers.size();
		sampler->activeTexture = getActiveTexture(sampler->rank);
		samplers.push_back(sampler);
	}

	void Material::addFloatUniform(const char * uniformName, float f) {
		unsigned int location = glGetUniformLocation(programID, uniformName);
		floatUniforms.insert(pair<unsigned int, float>(location, f));
	}

	void Material::addVec3Uniform(const char * uniformName, glm::vec3 & vec) {
		unsigned int location = glGetUniformLocation(programID, uniformName);
		vec3Uniforms.insert(pair<unsigned int, glm::vec3>(location, vec));
	}

	void Material::addVec4Uniform(const char * uniformName, glm::vec4 & vec) {
		unsigned int location = glGetUniformLocation(programID, uniformName);
		vec4Uniforms.insert(pair<unsigned int, glm::vec4>(location, vec));
	}

	void Material::bindUniforms() {
		for (auto sampler : samplers)
			bindSampler(sampler);

		for (auto vec : vec3Uniforms)
			glUniform3fv(vec.first, 1, &vec.second[0]);
		for (auto vec : vec4Uniforms)
			glUniform4fv(vec.first, 1, &vec.second[0]);
		for (auto f : floatUniforms)
			glUniform1f(f.first, f.second);
	}

	void Material::bind() {
		glUseProgram(programID);
		bindUniforms();
	}

	void Material::unbind() {
		glUseProgram(0);
	}
}