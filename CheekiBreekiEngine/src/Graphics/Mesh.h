#pragma once
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>
#include <vector>

namespace CheekiBreekiEngine {
	class Mesh {
		struct MeshEntry {
			enum BUFFERS {
				VERTEX_BUFFER, TEXCOORD_BUFFER, NORMAL_BUFFER, INDEX_BUFFER
			};
			unsigned int vao;
			unsigned int vbo[4];

			unsigned int elementCount;

			MeshEntry(aiMesh *mesh);
			~MeshEntry();

			void render();
		};

		std::vector<MeshEntry*> meshEntries;
	public:
		~Mesh();

		void loadFromFile(std::string);

		void render();
	};
}
