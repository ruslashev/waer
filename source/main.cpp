#include "physics.hpp"
#include "renderer.hpp"

void start()
{
	Renderer drawer;
	std::vector<Particle> particles;

	for (int i = 0; i < 100; i++) {
		particles.push_back(Particle(rand() % 700 + 10, rand() % 200 + 10));
	}

	drawer.MainLoop(particles);
}

int main()
{
	try {
		start();
	} catch (std::exception &e) {
		fprintf(stderr, "\x1b[31m" "ERROR" "\x1b[0m" " %s", e.what());
	}

	return 0;
}

