/*
 * MusicFile.cpp
 *
 *  Created on: Jan 8, 2016
 *      Author: Erons J
 */

#include "Musiclyrics.h"
#include <iostream>
namespace emo {

Musiclyrics::Musiclyrics(Mix_Music *pMusic, std::string lfile): m_musicFile(pMusic), m_lyrics(lfile){

}

bool Musiclyrics::displayLyrics(){
	std::ifstream inFile(m_lyrics);
	if(inFile == NULL) return false;

	std::string words;

	while(!inFile.eof()){
		getline(inFile, words);
		std::cout << words << std::endl;
	}

	return true;
}


Musiclyrics::~Musiclyrics() {
	// TODO Auto-generated destructor stub
}

} /* namespace emo */
