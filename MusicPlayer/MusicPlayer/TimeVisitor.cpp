///////////////////////////////////////////////////////////////////////////
// Workfile : TimeVisitor.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class TimeVisitor
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "TimeVisitor.h"

void TimeVisitor::Visit(Song* song)
{
	try
	{
		if(song == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mTime = mTime + song->GetTime();
	}
	catch (std::string const& error)
	{
		std::cout << "error in TimeVisitor::Visit(Song*): " << error << std::endl;
	}
}

void TimeVisitor::Visit(Album* album)
{
	try
	{
		if(album == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		album->GetTime(this);
	}
	catch (std::string const& error)
	{
		std::cout << "error in TimeVisitor::Visit(Album*): " << error << std::endl;
	}
}

void TimeVisitor::Visit(MusicCollection* musicCollection)
{
	try
	{
		if(musicCollection == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		musicCollection->GetTime(this);
	}
	catch (std::string const& error)
	{
		std::cout << "error in TimeVisitor::Visit(MusicCollection*): " << error << std::endl;
	}
}

size_t TimeVisitor::GetTime() const
{
	return mTime;
}