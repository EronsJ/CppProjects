/*
 * Screen.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: Erons J
 */

#include "Screen.h"
#include <cstring>

namespace emo {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {
}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return 2;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	std::memset(m_buffer1, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	std::memset(m_buffer2, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));


	return true;
}


void Screen::boxBlurH(int x, int y, int* redTotal, int* greenTotal, int* blueTotal){
	Uint32 color = m_buffer2[y * SCREEN_WIDTH + x];

	(*redTotal) += ((0xff) & (color >> 24));
	(*greenTotal) += ((0xff) & (color >> 16));
	(*blueTotal) += ((0xff) & (color >> 8));

}

void Screen::boxBlur(){
	//Swap the buffer so pixeL is in m_bufer2 and we are drawing to m_buffer1

	Uint32 *temp =  m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for(int y = 0; y < Screen::SCREEN_HEIGHT; y++){
		for(int x = 0; x < Screen::SCREEN_WIDTH; x++){
			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;
			for(int row = -1; row <= 1; row++){
				for(int col = -1; col <=1; col++){
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT){
						boxBlurH(currentX, currentY, &redTotal, &greenTotal, &blueTotal);
					}
				}
			}

			Uint8 red = redTotal /9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x, y, red,green,blue);

		}

	}

}
void Screen::close() {


	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}
bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
	Uint32 color = 0;

	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) return;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer1[(y * SCREEN_WIDTH)+x] = color;
}


void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	//SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

}

}

