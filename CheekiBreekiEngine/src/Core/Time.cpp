#include <Core\Time.h>


namespace CheekiBreekiEngine {
	Time* Time::_instance = nullptr;
	void Time::start() {
		_firstTime = _lastTime = _currentTime = steady_clock::now();
	}

	void Time::update() {
		_currentTime = steady_clock::now();
		_deltaTime = _currentTime - _lastTime;
		_lastTime = _currentTime;
	}

	void Time::setStaticInstance(Time * _instance) {
		Time::_instance = _instance;
	}

	double Time::elapsedTime() {
		return (_instance->_lastTime - _instance->_firstTime).count();
	}

	double Time::deltaTime() {
		return _instance->_deltaTime.count();
	}

	nanoseconds Time::deltaTimeNano() {
		return _instance->_deltaTime;
	}


}