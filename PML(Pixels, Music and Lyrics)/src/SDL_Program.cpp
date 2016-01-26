//============================================================================
// Name        : SDL_Program.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <cmath>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"
#include "MusicController.h"
using namespace std;
using namespace emo;



int main(int argc, char *argv[]) {
	MusicController music;
	if (!music.start()){
		cout << "We have a problem" << music.getErrorMessage() << endl;
	}

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << music.getErrorMessage() << endl;
	}

	Swarm swarm;
	int elapsed;
	while (true) {


		//Draw Particles
		elapsed = SDL_GetTicks();


		swarm.update(elapsed);

		//update particles
		unsigned char green = (unsigned char)((1 + sin((elapsed * 0.0001)- 2.0943951))*128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002))*128);
		unsigned char blue =(unsigned char)((1 + sin(elapsed * 0.0005))*128);

		const Particle *const pParticle = swarm.getParticles();

		for(int i = 0; i < Swarm::MPARTICLE; i++){
			Particle particle = pParticle[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y) * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x,y, red, green, blue);
		}


		screen.boxBlur();

		//Draw the Screen
		screen.update();


		//Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}

		if(!music.isPlaying()){
			break;
		}
	}

	screen.close();

	return 0;
}
