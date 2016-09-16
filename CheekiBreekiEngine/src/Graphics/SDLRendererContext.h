#pragma once
#pragma once
#include <Graphics\RendererContext.h>
#include <SDL.h>

namespace CheekiBreekiEngine {
	class SDLRendererContext : public RendererContext {
		SDL_Window *mainwindow; /* Our window handle */
		SDL_GLContext maincontext; /* Our opengl context handle */

		// Inherited via RendererContext
		virtual void initialize() override;
		virtual void paint() override;

		// Inherited via RendererContext
		virtual void terminate() override;
	};
}