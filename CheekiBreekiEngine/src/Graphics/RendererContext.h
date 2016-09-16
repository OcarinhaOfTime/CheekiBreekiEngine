#pragma once
namespace CheekiBreekiEngine {
	class RendererContext{
	public:
		virtual void initialize() = 0;
		virtual void paint() = 0;
		virtual void terminate() = 0;
	};
}