#pragma once
#include <GL\glew.h>
#include <QtOpenGL\qgl.h>


namespace CheekiBreekiEngine {
	class Renderer : public QGLWidget {
	protected:
		void initializeGL();
		void paintGL();
	public:
		void start();
		void update();
		void terminate();
		// start
		// send data
		// update elements
		// clean data
	};
}