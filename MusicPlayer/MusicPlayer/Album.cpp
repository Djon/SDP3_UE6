///////////////////////////////////////////////////////////////////////////
// Workfile : Album.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Implementation of class Album
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include "Album.h"

//CTor
Album::Album(std::string Name, std::string Interpret)
	: mInterpret(Interpret)
{
	mName = Name;
}

//virtual Destructor
Album::~Album()
{

}

void Album::Accept(Visitor* visitor)
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
		std::cout << "Error in Album::Accept: " << error << std::endl;
	}
}

void Album::Play()
{

}

void Album::GetTime()
{
	try
	{
		if(tmpVisitor == 0)
		{
			std::string error = "no valid visitor";
			throw (error); 
		}
		std::for_each(mSongs.begin(),mSongs.end(),[=](Song* s)
		{
			s->Accept(tmpVisitor);
		});

		//make sure GetTime will not be called outside of a Visitor
		tmpVisitor = 0;
	}
	catch (std::string const& error)
	{
		std::cout << "Error in Album::GetTime: " << error << std::endl;
	}
}