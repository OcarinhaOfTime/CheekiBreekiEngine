#include <Core\MainLoop.h>
#include <iostream>

using namespace std;

namespace CheekiBreekiEngine {
	int MainLoop::init() {
		//entities initialization
		_time.start();
		_time.setStaticInstance(&_time);

		while (true) {
			_time.update();
			cout << "elapsed time: " << Time::elapsedTime() << endl;
		}
		return 0;
	}
}