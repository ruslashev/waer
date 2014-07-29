#include "renderer.hpp"

int main()
{
	try {
	Renderer drawer;

	drawer.Draw();
	} catch (std::exception &e) {
		fprintf(stderr, "\x1b[31m" "ERROR" "\x1b[0m" " %s", e.what());
	}

	return 0;
}

