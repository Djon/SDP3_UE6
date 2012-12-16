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

typedef std::list<Song*> SongList;

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

	void GetTime();

private:
	std::string mInterpret;

	Visitor* tmpVisitor;
	SongList mSongs;
};

#endif