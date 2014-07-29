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
		throw std::runtime_error(outputStr);
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

	SDL_SetRenderDrawColor(_renderer, 20, 20, 20, 255);
	SDL_RenderClear(_renderer);

	SDL_Surface *squareSurf = SDL_LoadBMP("square.bmp");
	assertf(squareSurf != NULL,
			"Failed to load image \"square.bmp\": %s", SDL_GetError());
	_square = SDL_CreateTextureFromSurface(_renderer, squareSurf);
	SDL_FreeSurface(squareSurf);
}

void Renderer::MainLoop(std::vector<Particle> &particles)
{
	SDL_Event event;
	bool done = false;
	double time = 0.0;
	const double dt = 0.01;

	double currentTime = SDL_GetTicks() / 1000.0;
	double accumulator = 0.0;

	while (!done) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT)
				done = true;
		}

		const double newTime = SDL_GetTicks() / 1000.0;
		const double frameTime = newTime - currentTime;
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt) {
			for (auto &p : particles)
				p.Update(dt);
			accumulator -= dt;
			time += dt;
		}

		SDL_RenderClear(_renderer);

		SDL_Rect dest = { 0, 0, 5, 5 };
		for (auto &p : particles) {
			dest.x = p.position.x;
			dest.y = p.position.y;
			SDL_RenderCopy(_renderer, _square, NULL, &dest);
		}

		SDL_RenderPresent(_renderer);
	}
}

Renderer::~Renderer()
{
	SDL_DestroyTexture(_square);
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

