#include "RenderableTest.h"

namespace CheekiBreekiEngine {
	RenderableTest::RenderableTest() {


		cam = new PerspectiveCamera(45);
		cam->setPosition(glm::vec3(0, 0, -5));
		transform = new Transform;

		mesh = new Mesh;
		shader = new Shader;
		material = new Material();
	}
	void RenderableTest::start() {

		mesh->loadFromFile("Assets/Meshes/suzanne.obj");
		shader->loadFromFile("Assets/Shaders/passThrough");

		material->initialise(shader);
		
	}
	void RenderableTest::update() {
		material->bind();
		material->setMVP(cam->VPMtx() * transform->modelMtx());
		mesh->render();
	}
	void RenderableTest::terminate() {

	}
}