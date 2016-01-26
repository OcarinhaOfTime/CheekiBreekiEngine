#include <Graphics\Renderer.h>
#include <cassert>
#include <QtWidgets\qapplication.h>

#include <IL\il.h>
#include <IL\ilu.h>
#include <IL\ilut.h>

#include <CheekiBreekiDebug.h>

namespace CheekiBreekiEngine {
	void Renderer::initializeGL() {
		GLenum errorCode = glewInit();
		assert(errorCode == 0);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);

		//initializing texture libraries
		ilInit();
		iluInit();
		ilutInit();

		ilutRenderer(ILUT_OPENGL);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		glClearColor(0, 0, 0, 0);
	}

	void Renderer::paintGL() {
		glViewport(0, 0, width(), height());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//update graphics here
		cout << "updating graphics..." << endl;
	}

	void Renderer::start() {
		int argc = 0;
		char** argv;
		QApplication app(argc, argv);

		initializeGL();

		app.exec();
	}

	void Renderer::update() {
		repaint();
	}

	void Renderer::terminate() {
	}


}