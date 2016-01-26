/*
 * MusicFile.h
 *
 *  Created on: Jan 8, 2016
 *      Author: Erons J
 */

#ifndef MUSICLYRICS_H_
#define MUSICLYRICS_H_
#include <SDL_mixer.h>
#include <fstream>
namespace emo {

class Musiclyrics {
private:
	Mix_Music* m_musicFile;
	std::string m_lyrics;

public:
	Musiclyrics(Mix_Music*, std::string);
	//bool buildLyrics( ); Will be used to get lyrics from online sources
	bool displayLyrics();
	virtual ~Musiclyrics();
};

} /* namespace emo */

#endif /* MUSICLYRICS_H_ */
