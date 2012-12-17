///////////////////////////////////////////////////////////////////////////
// Workfile : Album.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Header for Album.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef ALBUM_H
#define ALBUM_H

#include "MusicComponent.h"
#include "Song.h"

class Album : 
	public MusicComponent
{
public:
	//CTor
	Album(std::string Name, std::string Interpret);

	//virtual Destructor
	virtual ~Album();

	virtual void Accept(Visitor* visitor);	
	virtual void Play(Visitor* visitor);

	virtual TMusicKind GetType();
	void GetTime(Visitor* visitor);
	std::string GetInterpret();
	size_t GetNumberOfEntries();

	virtual void AddMusic(MusicComponent* m);

private:
	std::string mInterpret;
	MusicList mSongs;
};

#endif