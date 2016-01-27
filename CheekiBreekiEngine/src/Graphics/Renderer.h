#pragma once

namespace CheekiBreekiEngine {
	class Renderer {
	public:
		int init(int argc, char* argv[]);
		void start();	// must creates it's context, 
		void update();
		void terminate();
		// start
		// send data
		// update elements
		// clean data
	};
}