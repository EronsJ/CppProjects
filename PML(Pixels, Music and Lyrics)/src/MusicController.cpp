/*
 * MusicController.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: Erons J
 */

#include "MusicController.h"
#include <SDL.h>

namespace emo {

MusicController::MusicController(const char * musicfile, std::string lyrics = "") :
		DEFAULT_MUSIC_FILE("Recording(13).mp3"), m_musicFileName(
				(musicfile == NULL) ?
						DEFAULT_MUSIC_FILE : musicfile), m_FLAGS(MIX_INIT_MP3), m_pMusicFile(
		NULL), m_Frequency(44100), m_Format(AUDIO_S16SYS), m_Channel(2), m_ChunkSize(
				4096),  m_lyricFileName(lyrics) {
}

MusicController::MusicController() :
		DEFAULT_MUSIC_FILE("Recording(13).mp3"), m_musicFileName(DEFAULT_MUSIC_FILE), m_FLAGS(MIX_INIT_MP3), m_pMusicFile(
		NULL), m_Frequency(44100), m_Format(AUDIO_S16SYS), m_Channel(2), m_ChunkSize(
				4096), m_lyricFileName("Recording(13).txt"){
}

bool MusicController::start() {

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		m_ErrorMessage =  "Can not initialize SDL\n";
		return false;
	}

	int result = Mix_Init(m_FLAGS);
	if (m_FLAGS != result) {
		m_ErrorMessage =  "flags: " + m_FLAGS;
		m_ErrorMessage += "\nMix_Init: " + result;
		m_ErrorMessage += "\nThe problem is: " + ((std::string)Mix_GetError()) + "\n";
		return false;
	}

	if (!configureAudio(m_Frequency, m_Format, m_Channel, m_ChunkSize)) {
		m_ErrorMessage =  "Didn't open audio device: " + (std::string)Mix_GetError()
				+ "\n";
		return false;
	}

	if (!loadMP3MusicFile(m_musicFileName)) {
		m_ErrorMessage =  "Failed to load music: " + (std::string)Mix_GetError() + "\n";
		return false;
	}

	if( m_lyricFileName == ""){
		m_ErrorMessage = "file " + m_lyricFileName +" not found";
		return true;
	}

	Musiclyrics lyrics(m_pMusicFile, m_lyricFileName );

	lyrics.displayLyrics();


	if (!playMusic()) {
		m_ErrorMessage =  "Music not playing: " + (std::string) Mix_GetError() + "\n";
		return false;
	}


	return true;

}

bool MusicController::configureAudio(int freq, Uint16 format, int channel,
		int chunksize) {
	if (isPlaying()){
		m_ErrorMessage +=  "Music is playing\n";
		return false;
	}
	Mix_CloseAudio();
	m_Frequency = freq;
	m_Format = format;
	m_Channel = channel;
	m_ChunkSize = chunksize;
	return (Mix_OpenAudio(m_Frequency, m_Format, m_Channel, m_ChunkSize) == 0);

}

bool MusicController::loadMP3MusicFile(const char *p) {
	m_pMusicFile = Mix_LoadMUS(p);
	return (m_pMusicFile != NULL);
}

bool MusicController::playMusic(int numberOfTimes) {
	return (Mix_PlayMusic(m_pMusicFile, numberOfTimes) == 0);
}

bool MusicController::isPlaying(){
	return (Mix_PlayingMusic() == 1);
}

std::string MusicController::getErrorMessage(){
	return m_ErrorMessage;
}

MusicController::~MusicController() {
	Mix_FreeMusic(m_pMusicFile);
	m_pMusicFile = NULL;
	Mix_CloseAudio();
	Mix_Quit();
}

} /* namespace emo */
