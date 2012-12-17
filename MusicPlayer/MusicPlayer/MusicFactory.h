///////////////////////////////////////////////////////////////////////////
// Workfile : MusicFactory.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Header for MusicFactory.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MUSICFACTORY_H
#define MUSICFACTORY_H

#include "Object.h"
#include "TMusicKind.h"
#include "MusicComponent.h"

class MusicFactory : 
	public Object
{
public:
	//virtual Destructor
	virtual ~MusicFactory();

	MusicComponent* CreateMusicCollection(std::string Name);
	MusicComponent* CreateAlbum(std::string Name, std::string Interpret);
	MusicComponent* CreateSong(std::string Name, std::string Album, std::string Interpret, size_t time);

private:
	MusicList mMusicComponents;
};

#endif