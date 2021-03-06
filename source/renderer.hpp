#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "physics.hpp"

#include <SDL2/SDL.h>
#include <string>
#include <stdexcept>

class Renderer
{
	SDL_Window *_window;
	SDL_Renderer *_renderer;
	SDL_Texture *_square;
public:
	Renderer();
	void MainLoop(std::vector<Particle> &particles);
	~Renderer();
};

void assertf(bool condition, const char *format, ...);

#endif

