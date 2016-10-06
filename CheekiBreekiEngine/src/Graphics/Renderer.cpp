#include <GL\glew.h>

#include <CheekiBreekiDebug.h>
#include <cassert>

#include <IL\il.h>
#include <IL\ilu.h>
#include <IL\ilut.h>

#include <CheekiBreekiDebug.h>
#include <Core\MainLoop.h>

#include <Graphics\Renderer.h>
#include <CheekiBreekiDebug.h>
#include <Graphics\RendererContext.h>
#include <Graphics\GLFWRendererContext.h>

namespace CheekiBreekiEngine {
	//Initialise openGL and other graphics libs
	int Renderer::init(int argc, char * argv[]) {
		cout << "initializeGL()" << endl;
		rendererContext = new GLFWRendererContext("HUE", 1024, 768);
		rendererContext->initialize();

		GLenum errorCode = glewInit();
		cout << errorCode << endl;
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

		glClearColor(0, 0, .2f, 0);
		return 0;
	}
	void Renderer::start() {
		for (auto renderable : renderables)
			renderable->start();
	}

	void Renderer::update() {
		//glViewport(0, 0, 1024, 768);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto renderable : renderables)
			renderable->update();

		rendererContext->paint();
	}

	void Renderer::terminate() {
		for (auto renderable : renderables)
			renderable->terminate();

		rendererContext->terminate();
	}

	void Renderer::addRenderable(Renderable * renderable) {
		this->renderables.insert(this->renderables.end(), renderable);
	}

	void Renderer::removeRenderable(Renderable *renderable) {
		this->renderables.remove(renderable);
	}
}