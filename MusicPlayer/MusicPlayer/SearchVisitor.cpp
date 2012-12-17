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
		std::cerr << "error in SearchVisitor::SearchVisitor: " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "SearchVisitor::Visit: Unknown Exception occured" << std::endl;
	}
}

void SearchVisitor::Visit(Song* song)
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
		std::cerr << "error in SearchVisitor::Visit(Song*): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "SearchVisitor::Visit: Unknown Exception occured" << std::endl;
	}
}

void SearchVisitor::Visit(Album* album)
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
		album->ForwardVisitor(this);
	}
	catch (std::string const& error)
	{
		std::cerr << "error in SearchVisitor::Visit(Album*): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "SearchVisitor::Visit: Unknown Exception occured" << std::endl;
	}
}

void SearchVisitor::Visit(MusicCollection* musicCollection)
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
		musicCollection->ForwardVisitor(this);
	}
	catch (std::string const& error)
	{
		std::cerr << "error in SearchVisitor::Visit(MusicCollection*): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "SearchVisitor::Visit: Unknown Exception occured" << std::endl;
	}
}

TMusicComponents* SearchVisitor::GetResults()
{
	return &mResults;
}