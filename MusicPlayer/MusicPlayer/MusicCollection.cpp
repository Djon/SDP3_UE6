///////////////////////////////////////////////////////////////////////////
// Workfile : MusicCollection.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Implementation of class MusicCollection
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include "MusicCollection.h"
#include "Visitor.h"

//CTor
MusicCollection::MusicCollection(std::string Name)
{
	mName = Name;
	mType = TMusicCollection;
}

//virtual Destructor
MusicCollection::~MusicCollection()
{}

void MusicCollection::Accept(Visitor* visitor)
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
		std::cerr << "Error in MusicCollection::Accept: " << error << std::endl;
	}
}

void MusicCollection::Play(Visitor* visitor)
{
	try
	{
		if(visitor == 0)
		{
			std::string error = "no valid visitor";
			throw (error); 
		}
		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=](MusicComponent* m)
		{
			m->Accept(visitor);
		});
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in MusicCollection::Play: " << error << std::endl;
	}
}

void MusicCollection::GetTime(Visitor* visitor)
{
	try
	{
		if(visitor == 0)
		{
			std::string error = "no valid visitor";
			throw (error); 
		}
		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=](MusicComponent* m)
		{
			m->Accept(visitor);
		});
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in MusicCollection::GetTime: " << error << std::endl;
	}
}

TMusicKind MusicCollection::GetType()
{
	return mType;
}

void MusicCollection::AddMusic(MusicComponent* m)
{
	try
	{
		if(m == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mMusicComponents.push_back(m);
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in MusicCollection::AddMusic: " << error << std::endl;
	}
}

size_t MusicCollection::GetNumberOfEntries()
{
	size_t counter = 0;
	std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=, &counter](MusicComponent* m)
	{
		counter += m->GetNumberOfEntries();
	});
	return counter;
}