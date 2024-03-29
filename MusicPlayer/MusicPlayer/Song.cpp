///////////////////////////////////////////////////////////////////////////
// Workfile : Song.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Implementation of class Song
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Song.h"
#include "Visitor.h"

//CTor
Song::Song(std::string Name, std::string Album, std::string Interpret, size_t time)
	: mAlbum(Album),mInterpret(Interpret),mTime(time)
{
	mName = Name;
	mType = TSong;
}

//virtual Destructor
Song::~Song()
{}

void Song::Accept(Visitor* visitor)
{
	try
	{
		if(visitor == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		visitor->Visit(this);
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in Song::Accept: " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "Song::Accept: Unknown Exception occured" << std::endl;
	}
}

size_t Song::GetTime()
{
	return mTime;
}

std::string Song::GetInterpret()
{
	return mInterpret;
}

void Song::AddMusic(MusicComponent* m)
{
	std::string error = "This functions is not implemented and should not be used";
	std::cerr << "Error in Song::AddMusic: " << error << std::endl;
}

TMusicKind Song::GetType()
{
	return mType;
}

size_t Song::GetNumberOfEntries()
{
	return 1;
}