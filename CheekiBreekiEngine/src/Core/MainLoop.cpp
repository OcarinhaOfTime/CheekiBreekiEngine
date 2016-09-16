#include <Core\MainLoop.h>
#include <Graphics\Renderer.h>

#include <CheekiBreekiDebug.h>

namespace CheekiBreekiEngine {
	bool MainLoop::running = true;

	int MainLoop::init(int argc, char* argv[]) {
		//entities initialization
		_time.start();
		_time.setStaticInstance(&_time);
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