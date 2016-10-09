#include <Core\RenderableTest.h>
#include <Graphics\OrthographicCamera.h>

namespace CheekiBreekiEngine {
	RenderableTest::RenderableTest() {


		cam = new OrthographicCamera();
		transform = new Transform;
		transform->setPosition(glm::vec3(-5, 5, 0));

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