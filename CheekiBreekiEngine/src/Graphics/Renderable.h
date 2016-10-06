#pragma once
namespace CheekiBreekiEngine {
	class Renderable {
	public:
		virtual void start() = 0;
		virtual void update() = 0;
		virtual void terminate() = 0;
	};
}