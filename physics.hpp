#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <vector>

struct vec2
{
	double x, y;
	vec2 operator+ (vec2 r) { return vec2(x + r.x, y + r.y); }
	vec2() {};
	vec2(double a, double b) : x(a), y(b) {};
};

struct Particle
{
	vec2 position, prev_postion;
	vec2 acceleration;

	Particle(double x, double y) { position.x = x; position.y = y; }
	void Update(double dt);
};

#endif

