/*
 * Particle.h
 *
 *  Created on: Mar 25, 2015
 *      Author: Erons J
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <random>
#include <ctime>
#include <cmath>

namespace emo {

struct Particle {
	const double m_PI = 4 * std::atan(1);
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace emo */

#endif /* PARTICLE_H_ */
