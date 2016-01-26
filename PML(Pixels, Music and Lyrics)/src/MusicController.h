/*
 * MusicController.h
 *
 *  Created on: Jan 7, 2016
 *      Author: Erons J
 */

#ifndef MUSICCONTROLLER_H_
#define MUSICCONTROLLER_H_
#include <SDL_mixer.h>
#include <string>
#include "Musiclyrics.h"

namespace emo {

class MusicController {
private:


	const char * DEFAULT_MUSIC_FILE;
	const char * m_musicFileName;
	const int m_FLAGS;
	Mix_Music* m_pMusicFile;
	int m_Frequency;
	Uint16 m_Format;
	int m_Channel;
	int m_ChunkSize;
	std::string m_ErrorMessage;
	std::string m_lyricFileName;

public:
	MusicController();
	MusicController(const char *, std::string lyrics);
	bool configureAudio(int freq, Uint16 format, int channel, int chunksize);
	bool loadMP3MusicFile(const char *);
	bool playMusic(int NumberofTimes = 1);
	bool start();
	bool isPlaying();
	std::string getErrorMessage();
	void setErrorMessage();
	virtual ~MusicController();
};

} /* namespace emo */

#endif /* MUSICCONTROLLER_H_ */
