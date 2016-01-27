#pragma once
#include <QtOpenGL\qgl.h>
namespace CheekiBreekiEngine {
	class RendererContext : public QGLWidget {
	protected:
		void initializeGL();
		void paintGL();
	};
}