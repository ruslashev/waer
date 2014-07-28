#include <fstream>
#include <SDL2/SDL.h>

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

int main()
{
	assertf(SDL_Init(SDL_INIT_VIDEO) >= 0,
			"Failed to initialize SDL: %s", SDL_GetError());

	SDL_Window *window = SDL_CreateWindow("Water Simulator",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			800, 600,
			0);
	assertf(window != NULL, "Failed to create window: %s", SDL_GetError());

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	assertf(renderer != NULL, "Failed to create renderer: %s", SDL_GetError());

	SDL_Delay(1000);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}

