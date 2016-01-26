#pragma once
#include <chrono>
#include <Core\Entity.h>

using namespace std::chrono;
namespace CheekiBreekiEngine{
	class Time {
		time_point<steady_clock> _lastTime;
		time_point<steady_clock> _firstTime;
		time_point<steady_clock> _currentTime;

		nanoseconds _deltaTime;
		static Time* _instance;
	public:
		void start();
		void update();
		void setStaticInstance(Time* _instance);

		static double elapsedTime();
		static double deltaTime();
		static nanoseconds deltaTimeNano();
	};
}