#include <Core\MainLoop.h>
#include <Graphics\Renderer.h>

#include <CheekiBreekiDebug.h>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "RenderableTest.h"

using namespace std;

namespace CheekiBreekiEngine {
	bool MainLoop::running = true;

	template <typename T>
	bool foo(T x, T y) {
		return x < y;
	}

	int MainLoop::init(int argc, char* argv[]) {
		Renderer renderer;
		Renderable* renderable = &RenderableTest();

		RenderableTest* renderable2 = new RenderableTest;
		renderable2->transform->setPosition(glm::vec3(-2, 0, 0));
		RenderableTest* renderable3 = new RenderableTest;
		renderable3->transform->setPosition(glm::vec3(2, 0, 0));
		renderable3->transform->setRotation(90, glm::vec3(1, 0, 0));
		

		thread rendererThread([&] {
			renderer.init(argc, argv);
			renderer.addRenderable(renderable);
			renderer.addRenderable(renderable2);
			renderer.addRenderable(renderable3);
			renderer.start();

			while (running) {
				renderer.update();
			}
			renderer.terminate();
		});

		rendererThread.join();

		//while (running) {
			//check for user input
			//run AI
			//get network packets 
			//update all objects in the world
			//render
		//}
		//terminate all entitie
		return 0;
	}
}