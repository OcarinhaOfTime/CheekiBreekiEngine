#pragma once
#include <Graphics\RendererContext.h>
#include <GLFW\glfw3.h>
namespace CheekiBreekiEngine {
	class GLFWRendererContext : public RendererContext {
		GLFWwindow* window;
		char* windowName = "";
		int width = 1024;
		int height = 768;

		virtual void initialize() override;
		virtual void paint() override;
		virtual void terminate() override;

	public:
		GLFWRendererContext();
		GLFWRendererContext(char* windowName, int width, int height);
	};
}