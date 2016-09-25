#include <Core\MainLoop.h>
#include <Graphics\Renderer.h>

#include <CheekiBreekiDebug.h>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

namespace CheekiBreekiEngine {
	bool MainLoop::running = true;

	template <typename T>
	bool foo(T x, T y) {
		return x < y;
	}

	int MainLoop::init(int argc, char* argv[]) {
		Renderer renderer;
		

		thread rendererThread([&] {
			renderer.init(argc, argv);
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