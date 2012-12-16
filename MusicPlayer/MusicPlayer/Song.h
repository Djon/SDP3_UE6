///////////////////////////////////////////////////////////////////////////
// Workfile : Song.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Header for Song.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef SONG_H
#define SONG_H

#include "MusicComponent.h"

class Song : 
	public MusicComponent
{
public:
	//CTor
	Song(std::string Name, std::string Album, std::string Interpret, size_t time);

	//virtual Destructor
	virtual ~Song();

	virtual void Accept(Visitor* visitor);	
	virtual void Play();

	size_t GetTime();

private:
	std::string mAlbum;
	std::string mInterpret;

	size_t mTime;
};

#endif