///////////////////////////////////////////////////////////////////////////
// Workfile : PlayVisitor.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class PlayVisitor
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "PlayVisitor.h"

void PlayVisitor::Visit(Song* song)
{
	try
	{
		if(song == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		song->Play();
	}
	catch (std::string const& error)
	{
		std::cout << "error in PlayVisitor::Visit(Song*): " << error << std::endl;
	}
}

void PlayVisitor::Visit(Album* album)
{
	try
	{
		if(album == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		album->Play();
	}
	catch (std::string const& error)
	{
		std::cout << "error in PlayVisitor::Visit(Album*): " << error << std::endl;
	}
}

void PlayVisitor::Visit(MusicCollection* musicCollection)
{
	try
	{
		if(musicCollection == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		musicCollection->Play();
	}
	catch (std::string const& error)
	{
		std::cout << "error in PlayVisitor::Visit(MusicCollection*): " << error << std::endl;
	}
}