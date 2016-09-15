#include <GL\glew.h>
#include <Graphics\RendererContext.h>
#include <CheekiBreekiDebug.h>
#include <cassert>

#include <IL\il.h>
#include <IL\ilu.h>
#include <IL\ilut.h>

#include <CheekiBreekiDebug.h>
#include <Core\MainLoop.h>

#include <Graphics\Mesh.h>
#include <Graphics\Shader.h>

namespace CheekiBreekiEngine {
	Mesh* mesh;
	Shader* shader;
	

	void RendererContext::initializeGL() {
		cout << "initializeGL()" << endl;
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

		glClearColor(0, 0, .2f, 0);

		mesh = new Mesh;
		mesh->loadFromFile("Assets/Meshes/suzanne.obj");

		shader = new Shader;
		shader->loadFromFile("Assets/Shaders/passThrough_Vertex.glsl", "Assets/Shaders/passThrough_Fragment.glsl");
		

	}

	void RendererContext::paintGL() {
		glViewport(0, 0, 1024, 768);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//update graphics here
		cout << "updating graphics..." << endl;
		shader->bind();
		mesh->render();
	}
}