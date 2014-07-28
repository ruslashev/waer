#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <string>

class Renderer
{
	SDL_Window *_window;
	SDL_Renderer *_renderer;
public:
	Renderer();
	void Draw();
	~Renderer();
};

void assertf(bool condition, const char *format, ...);

#endif

