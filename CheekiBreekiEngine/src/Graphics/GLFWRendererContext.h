#pragma once
#include <Graphics\RendererContext.h>
#include <GLFW\glfw3.h>
namespace CheekiBreekiEngine {
	class GLFWRendererContext : public RendererContext {
		GLFWwindow* window;
		// Inherited via RendererContext
		virtual void initialize() override;
		virtual void paint() override;

		// Inherited via RendererContext
		virtual void terminate() override;
	};
}