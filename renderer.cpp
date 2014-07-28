#include "renderer.hpp"

void assertf(bool condition, const char *format, ...)
{
	if (!condition) {
		char output[512];
		va_list args;
		va_start(args, format);
		vsnprintf(output, 512, format, args);
		va_end(args);
		std::string outputStr = output;
		outputStr += '\n';
		throw outputStr;
	}
}

Renderer::Renderer()
{
	assertf(SDL_Init(SDL_INIT_VIDEO) >= 0,
			"Failed to initialize SDL: %s", SDL_GetError());

	_window = SDL_CreateWindow("Water Simulator",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			800, 600,
			0);
	assertf(_window != NULL, "Failed to create window: %s", SDL_GetError());

	_renderer = SDL_CreateRenderer(_window, -1, 0);
	assertf(_renderer != NULL, "Failed to create renderer: %s", SDL_GetError());
}

void Renderer::Draw()
{
	SDL_Delay(1000);
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

