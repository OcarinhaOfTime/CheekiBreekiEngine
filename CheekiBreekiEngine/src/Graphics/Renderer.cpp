#include <Graphics\Renderer.h>
#include <QtWidgets\qapplication.h>
#include <Graphics\RendererContext.h>
#include <CheekiBreekiDebug.h>

namespace CheekiBreekiEngine {
	//Initialise openGL and other graphics libs
	int Renderer::init(int argc, char * argv[]) {
		cout << "Renderer::init()" << endl;
		QApplication app(argc, argv);

		RendererContext rendererContext;
		rendererContext.show();

		return app.exec();
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