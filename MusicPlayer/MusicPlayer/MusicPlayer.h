///////////////////////////////////////////////////////////////////////////
// Workfile : MusicPlayer.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of MusicPlayer.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <string>
#include "Object.h"
#include "MusicComponent.h"

typedef std::list<MusicComponent*>		 TMusicComponents;
typedef TMusicComponents::iterator TMusicComponentsItor;

class MusicPlayer :
	public Object
{
public:
	void Add(MusicComponent* musicComponent);
	size_t GetTime(MusicComponent * const musicComponent);
	size_t GetTotalTime();
	void Play();
	void Remove(MusicComponent * const musicComponent);
	void Search(std::string const& name);

private:
	TMusicComponents mMusicComponents;
};

#endif