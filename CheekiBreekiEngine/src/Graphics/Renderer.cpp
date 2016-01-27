#include <Graphics\Renderer.h>
#include <cassert>
#include <QtWidgets\qapplication.h>

#include <IL\il.h>
#include <IL\ilu.h>
#include <IL\ilut.h>

#include <CheekiBreekiDebug.h>
#include <Core\MainLoop.h>
#include <Graphics\RendererContext.h>

namespace CheekiBreekiEngine {
	void Renderer::start() {
		cout << "Renderer::start()" << endl;

		int argc = 0;
		char** argv;
		QApplication app(argc, argv);

		RendererContext rendererContext;

		app.exec();		
	}

	void Renderer::update() {
		//repaint();
	}

	void Renderer::terminate() {
	}


}