#include <Core\MainLoop.h>
#include <Graphics\Renderer.h>

#include <CheekiBreekiDebug.h>

namespace CheekiBreekiEngine {
	bool MainLoop::running = true;

	int MainLoop::init() {
		//entities initialization
		_time.start();
		_time.setStaticInstance(&_time);	

		//while (running) {
			//check for user input
			//run AI
			//get network packets 
			//update all objects in the world
			//render
		//}
		//terminate all entitie
		cout << "MainLoop::init()" << endl;
		Renderer renderer;
		renderer.start();
		return 0;
	}
}