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
	virtual void Play();

	virtual TMusicKind GetType();
	void GetTime();
	std::string GetInterpret();

	virtual void AddMusic(MusicComponent* m);

private:
	std::string mInterpret;

	Visitor* tmpVisitor;
	MusicList mSongs;
};

#endif