#pragma once
namespace CheekiBreekiEngine {
	class Component {
	public:
		virtual void render() = 0;
		virtual void start() = 0;
		virtual void update() = 0;
		virtual void destroy() = 0;
		virtual void physicsUpdate() = 0;
	};
}