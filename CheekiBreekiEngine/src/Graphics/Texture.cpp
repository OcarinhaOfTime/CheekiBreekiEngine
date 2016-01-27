#include <GL\glew.h>
#include <Graphics\Texture.h>

#include <IL\il.h>
#include <IL\ilut.h>

#include <CheekiBreekiDebug.h>

namespace CheekiBreekiEngine {
	wchar_t* charToWChar(const char* text) {
		size_t size = strlen(text) + 1;
		wchar_t* wa = new wchar_t[size];
		mbstowcs(wa, text, size);
		return wa;
	}

	void Texture::loadFromFile(std::string fileName) {
		ilGenImages(1, &imageId);
		ilBindImage(imageId);
		glGenTextures(1, &glTextureId);

		if (!ilLoadImage(charToWChar(fileName.c_str()))) {
			std::cout << "Couldn't load the image: " << fileName << " ";
			cout << ilGetError() << endl;
		}

		width = ilGetInteger(IL_IMAGE_WIDTH);
		height = ilGetInteger(IL_IMAGE_HEIGHT);
	}

	void Texture::bind() {
		glBindTexture(GL_TEXTURE_2D, glTextureId);
		ilBindImage(imageId);
		glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), width,
			height, 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
			ilGetData());
	}

	void Texture::unbind() {
		ilBindImage(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture() {
		ilDeleteImages(1, &imageId);
	}
}