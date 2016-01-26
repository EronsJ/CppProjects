/*
 * Screen.h
 *
 *  Created on: Mar 25, 2015
 *      Author: Erons J
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
namespace emo {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
public:
	Screen();
	bool init();
	void close();
	bool processEvents();
	void update();
	void clear();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();
	void boxBlurH(int, int, int*, int*, int*);

};

} /* namespace emo */

#endif /* SCREEN_H_ */
