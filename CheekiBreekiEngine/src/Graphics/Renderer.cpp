#include <Graphics\Renderer.h>
#include <Graphics\RendererContext.h>
#include <CheekiBreekiDebug.h>
#include <Graphics\SDLTest.h>

namespace CheekiBreekiEngine {
	//Initialise openGL and other graphics libs
	int Renderer::init(int argc, char * argv[]) {
		cout << "Renderer::init()" << endl;

		//RendererContext rendererContext;
		SDLTest t;
		t.Test();

		return 0;
	}
	void Renderer::start() {
		//rendererContext.show();
	}

	void Renderer::update() {
		//repaint();
	}

	void Renderer::terminate() {
	}


}