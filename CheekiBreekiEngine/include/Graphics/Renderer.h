#pragma once
#include <Graphics\RendererContext.h>
#include <list>
#include <Graphics\Renderable.h>

using std::list;

namespace CheekiBreekiEngine {
	class Renderer {
		RendererContext* rendererContext;
		list<Renderable*> renderables;
		int sada;

	public:
		int init(int argc, char* argv[]);
		void start();
		void update();
		void terminate();
		void addRenderable(Renderable*);
		void removeRenderable(Renderable*);
	};
}