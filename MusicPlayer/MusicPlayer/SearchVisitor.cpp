///////////////////////////////////////////////////////////////////////////
// Workfile : SearchVisitor.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class SearchVisitor
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "SearchVisitor.h"

SearchVisitor::SearchVisitor(std::string const& name)
{
	try
	{
		if(name == "")
		{
			std::string error = "no valid name";
			throw (error); 
		}
		mName = name;
	}
	catch (std::string const& error)
	{
		std::cout << "error in SearchVisitor::SearchVisitor: " << error << std::endl;
	}
}

void SearchVisitor::Visit(Song* song) const
{
	try
	{
		if(song == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		//check if searched name is part of name of the song
		if((song->GetName()).find(mName, 0) != std::string::npos)
		{
			mResults.push_back(song);
		}
	}
	catch (std::string const& error)
	{
		std::cout << "error in SearchVisitor::Visit(Song*): " << error << std::endl;
	}
}

void SearchVisitor::Visit(Album* album) const
{
	try
	{
		if(album == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		//check if searched name is part of name of the album
		if((album->GetName()).find(mName, 0) != std::string::npos)
		{
			mResults.push_back(album);
		}
	}
	catch (std::string const& error)
	{
		std::cout << "error in SearchVisitor::Visit(Album*): " << error << std::endl;
	}
}

void SearchVisitor::Visit(MusicCollection* musicCollection) const
{
	try
	{
		if(musicCollection == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		//check if searched name is part of name of the song
		if((musicCollection->GetName()).find(mName, 0) != std::string::npos)
		{
			mResults.push_back(musicCollection);
		}
	}
	catch (std::string const& error)
	{
		std::cout << "error in SearchVisitor::Visit(MusicCollection*): " << error << std::endl;
	}
}

TMusicComponents* SearchVisitor::GetResults()
{
	try
	{
		if(mResults == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		return &mResults;
	}
	catch (std::string const& error)
	{
		std::cout << "error in SearchVisitor::GetResults(): " << error << std::endl;
	}
}