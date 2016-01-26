/*
 * Swarm.h
 *
 *  Created on: Mar 25, 2015
 *      Author: Erons J
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace emo {

class Swarm {
public:
	const static int MPARTICLE = 5000;
private:
	Particle *const m_pParticle;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int);
	const Particle *const getParticles(){ return m_pParticle;}
};

} /* namespace emo */

#endif /* SWARM_H_ */
