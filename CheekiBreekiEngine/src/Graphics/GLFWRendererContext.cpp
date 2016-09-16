#include <Graphics\GLFWRendererContext.h>
#include <Core\MainLoop.h>

namespace CheekiBreekiEngine {
	void GLFWRendererContext::initialize() {
		/* Initialize the library */
		if (!glfwInit())
			return;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window) {
			glfwTerminate();
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(this->window);

		
	}

	void GLFWRendererContext::paint() {
		if (!glfwWindowShouldClose(this->window)) {

			/* Swap front and back buffers */
			glfwSwapBuffers(this->window);

			/* Poll for and process events */
			glfwPollEvents();
		}
		else {
			MainLoop::running = false;
		}
	}
	void GLFWRendererContext::terminate() {
		glfwTerminate();
	}
}