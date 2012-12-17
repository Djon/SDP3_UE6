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
		tmpVisitor = visitor;
		visitor->Visit(this);
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in MusicCollection::Accept: " << error << std::endl;
	}
}

void MusicCollection::Play()
{

}

void MusicCollection::GetTime()
{
	try
	{
		if(tmpVisitor == 0)
		{
			std::string error = "no valid visitor";
			throw (error); 
		}
		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=](MusicComponent* m)
		{
			m->Accept(tmpVisitor);
		});

		//make sure GetTime will not be called outside of a Visitor
		tmpVisitor = 0;
	}
	catch (std::string const& error)
	{
		std::cerr << "Error in Album::GetTime: " << error << std::endl;
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