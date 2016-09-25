#pragma once
#include <Graphics\RendererContext.h>

namespace CheekiBreekiEngine {
	class Renderer {
		RendererContext* rendererContext;
	public:
		int init(int argc, char* argv[]);
		void start();
		void update();
		void terminate();
	};
}