#include "physics.hpp"

void Particle::Update(double dt)
{
	acceleration = vec2(0, 50);

	const vec2 temp = position;
	position = position*2.0 - prev_postion + acceleration*dt*dt;
	prev_postion = temp;

	if (position.y > 595)
		position.y = 595;
}

