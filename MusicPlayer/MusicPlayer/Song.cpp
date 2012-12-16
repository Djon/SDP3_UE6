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
		std::cout << "Error in Song::Accept: " << error << std::endl;
	}
}

void Song::Play()
{

}

size_t Song::GetTime()
{
	return mTime;
}