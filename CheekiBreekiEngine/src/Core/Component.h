#pragma once
namespace CheekiBreekiEngine {
	class Component {
	public:
		virtual void render();
		virtual void start();
		virtual void update();
		virtual void destroy();
		virtual void physicsUpdate();
	};
}