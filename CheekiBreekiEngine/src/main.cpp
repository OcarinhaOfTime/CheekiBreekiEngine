#include <iostream>
#include <Core\MainLoop.h>

using namespace CheekiBreekiEngine;
int main(char** argv, int argc) {
	std::cout << "Hello Worlod" << std::endl;
	MainLoop mainLoop;
	return mainLoop.init();
}