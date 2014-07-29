#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <fstream>
#include <vector>

struct vec2
{
	double x, y;
	vec2 operator+ (const vec2 &o) { return vec2(x + o.x, y + o.y); }
	vec2 operator- (const vec2 &o) { return vec2(x - o.x, y - o.y); }
	vec2 operator* (const double &r) { return vec2(x*r, y*r); }
	vec2() {};
	vec2(double a, double b) : x(a), y(b) {};
};

struct Particle
{
	vec2 position, prev_postion;
	vec2 acceleration;

	Particle(double x, double y) { position = prev_postion = vec2(x, y); }
	void Update(double dt);
};

#endif

