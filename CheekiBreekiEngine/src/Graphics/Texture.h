#pragma once
#include <string>
namespace CheekiBreekiEngine {
	class Texture {
		unsigned int imageId;
		unsigned int glTextureId;
	public:
		float width;
		float height;
		void loadFromFile(std::string fileName);
		void bind();
		void unbind();
		~Texture();
	};
}
