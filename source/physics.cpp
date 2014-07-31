#include "physics.hpp"

const int MAX_ITERATIONS = 10;
const int DIST = 1000;

double distSq(const vec2 &a, const vec2 &b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

void UpdateParticles(double dt, std::vector<Particle> &particles)
{
	for (auto &p : particles) {
		// for (int count = 0; count < MAX_ITERATIONS; count++) {
			for (auto &i : particles) {
				if (&p == &i) {
					// puts("eq!");
					continue;
				}
				const double dist = distSq(p.position, i.position);
				if (dist > 1000) {
					continue;
				}

				const double divider = 1/50.;
				const double power = 1;
				double delta = p.position.x-i.position.x;
				p.acceleration.x += pow(delta/divider, power);
				i.acceleration.x -= pow(delta/divider, power);

				delta = p.position.y-i.position.y;
				p.acceleration.y += pow(delta/divider, power);
				i.acceleration.y -= pow(delta/divider, power);
			}
		// }
			p.Update(dt);
	}
}

void Particle::Update(double dt)
{
	acceleration = acceleration + vec2(0, 200);
	// acceleration = acceleration / 10;

	const vec2 temp = position;
	position = position*2.0 - prev_postion + acceleration*dt*dt;
	prev_postion = temp;

	const double offset = ((random() % 100) - 50) / 100.0;
	position.x = std::min(std::max(position.x, 5.0+offset), 795.0+offset);
	position.y = std::min(std::max(position.y, 5.0+offset), 595.0+offset);

	acceleration = vec2(0, 0);
}

