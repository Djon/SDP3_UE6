///////////////////////////////////////////////////////////////////////////
// Workfile : Album.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Implementation of class Album
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include "Album.h"
#include "Visitor.h"

//CTor
Album::Album(std::string Name, std::string Interpret)
	: mInterpret(Interpret)
{
	mName = Name;
	mType = TAlbum;
}

//virtual Destructor
Album::~Album()
{}

void Album::Accept(Visitor* visitor)
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
		std::cerr << "Error in Album::Accept: " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "Album::Accept: Unknown Exception occured" << std::endl;
	}
}

void Album::ForwardVisitor(Visitor* visitor)
{
	try
	{
		if(visitor == 0)
		{
			std::string error = "no valid visitor";
			throw (error); 
		}
		std::for_each(mSongs.begin(),mSongs.end(),[=](MusicComponent* s)
		{
			s->Accept(visitor);
		});
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in Album::ForwardVisitor: " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "Album::ForwardVisitor: Unknown Exception occured" << std::endl;
	}
}

void Album::AddMusic(MusicComponent* m)
{
	try
	{
		if(m == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		if(m->GetType() != TSong)
		{
			std::string error = "Tried to add a wrong object type to the song list";
			throw (error); 
		}
		mSongs.push_back(m);
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in Album::AddMusic: " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "Album::Accept: Unknown Exception occured" << std::endl;
	}
}

std::string Album::GetInterpret()
{
	return mInterpret;
}

TMusicKind Album::GetType()
{
	return mType;
}

size_t Album::GetNumberOfEntries()
{
	size_t counter = 0;
	std::for_each(mSongs.begin(),mSongs.end(),[=, &counter](MusicComponent* m)
	{
		counter += m->GetNumberOfEntries();
	});
	return counter;
}