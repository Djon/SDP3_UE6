///////////////////////////////////////////////////////////////////////////
// Workfile : MusicFactory.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Implementation of class MusicFactory
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include "MusicFactory.h"
#include "MusicCollection.h"
#include "Album.h"
#include "Song.h"

MusicFactory::~MusicFactory()
{
	std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[&](MusicComponent* m)
	{
		delete m;
	});
}

MusicComponent* MusicFactory::CreateMusicCollection(std::string Name)
{
	MusicComponent* m = new MusicCollection(Name);
	mMusicComponents.push_back(m);
	return m;
}

MusicComponent* MusicFactory::CreateAlbum(std::string Name, std::string Interpret)
{
	MusicComponent* m = new Album(Name,Interpret);
	mMusicComponents.push_back(m);
	return m;
}

MusicComponent* MusicFactory::CreateSong(std::string Name, std::string Album, std::string Interpret, size_t time)
{
	MusicComponent* m = new Song(Name,Album,Interpret,time);
	mMusicComponents.push_back(m);
	return m;
}