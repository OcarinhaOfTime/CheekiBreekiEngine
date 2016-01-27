#pragma once
#include <thread>
#include <Core\Time.h>
#include <Core\Entity.h>

using std::thread;

namespace CheekiBreekiEngine {
	class MainLoop {
		static const int maxEntities = 1;

		Time _time;
		enum Entities {
			GRAPHICS,
			PHYSICS,
			AUDIO
		};
		//thread entitiesThreads[maxEntities];
		Entity* entities[maxEntities];

	public:
		static bool running;
		int init();
	};
}
