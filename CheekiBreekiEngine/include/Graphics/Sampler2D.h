#pragma once
#include <Graphics\Texture.h>

namespace CheekiBreekiEngine {
	struct Sampler2D {
		Texture* texture;
		unsigned int textureWrapS;
		unsigned int textureWrapT;
		unsigned int activeTexture;
		unsigned int rank;
		unsigned int uniformLocation;
	};
}