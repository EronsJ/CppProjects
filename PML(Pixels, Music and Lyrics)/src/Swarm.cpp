/*
 * Swarm.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: Erons J
 */

#include "Swarm.h"

namespace emo {

Swarm::Swarm(): m_pParticle(new Particle[MPARTICLE]), lastTime(0){

}

Swarm::~Swarm() {
	delete m_pParticle;
}

void Swarm::update(int elapsed){

	int interval = elapsed - lastTime;
	for(int i = 0; i < Swarm::MPARTICLE; i++){
		m_pParticle[i].update(interval);
	}

	lastTime = elapsed;
}

} /* namespace emo */
