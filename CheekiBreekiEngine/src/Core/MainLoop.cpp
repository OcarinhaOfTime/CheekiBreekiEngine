#include <Core\MainLoop.h>

namespace CheekiBreekiEngine {
	int MainLoop::init() {
		//entities initialization
		_time.start();
		_time.setStaticInstance(&_time);

		

		while (true) {
			//check for user input
			//run AI
			//get network packets 
			//update all objects in the world
			//render
		}
		return 0;
	}
}