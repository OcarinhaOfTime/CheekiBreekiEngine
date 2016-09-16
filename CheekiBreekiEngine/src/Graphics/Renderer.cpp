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
#include <Graphics\SDLRendererContext.h>

#include <Graphics\Mesh.h>
#include <Graphics\Shader.h>
#include <Graphics\Texture.h>
#include <Graphics\Material.h>

namespace CheekiBreekiEngine {
	Mesh* mesh;
	Shader* shader;
	Material* material;
	Texture* texture;

	//Initialise openGL and other graphics libs
	int Renderer::init(int argc, char * argv[]) {
		cout << "initializeGL()" << endl;
		rendererContext = new GLFWRendererContext;
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
		mesh = new Mesh;
		mesh->loadFromFile("Assets/Meshes/suzanne.obj");

		//shader = new Shader;
		//shader->loadFromFile("Assets/Shaders/passThrough_Vertex.glsl", "Assets/Shaders/passThrough_Vertex.glsl");
		
	}

	void Renderer::update() {

		glViewport(0, 0, 1024, 768);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//update graphics here
		cout << "updating graphics..." << endl;
		//mesh->render();
		//shader->bind();
		rendererContext->paint();
	}

	void Renderer::terminate() {
		rendererContext->terminate();
	}


}