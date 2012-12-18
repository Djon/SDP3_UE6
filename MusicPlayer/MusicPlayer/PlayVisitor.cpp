///////////////////////////////////////////////////////////////////////////
// Workfile : PlayVisitor.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class PlayVisitor
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <iomanip>
#include "PlayVisitor.h"
#include "TimeVisitor.h"

PlayVisitor::PlayVisitor()
{
	mCounter = 0;
}

int PlayVisitor::GetMinutes(size_t const seconds)
{
	return seconds / 60;
}

int PlayVisitor::GetSeconds(size_t const seconds)
{
	return seconds % 60;
}

void PlayVisitor::Visit(Song* song)
{
	try
	{
		if(song == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mCounter++;
		std::cout << mCounter << ". " << song->GetName() << " << " << std::setfill('0') << std::setw(2) 
				  << GetMinutes(song->GetTime()) << ":" << GetSeconds(song->GetTime()) << " << " 
				  << song->GetInterpret() << std::endl;
	}
	catch (std::string const& error)
	{
		std::cerr << "error in PlayVisitor::Visit(Song*): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "PlayVisitor::Visit: Unknown Exception occured" << std::endl;
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

		TimeVisitor* timeVisitor = new TimeVisitor;

		album->Accept(timeVisitor);
		
		std::cout << "Album: " << album->GetName() << " (" << album->GetNumberOfEntries() << " Song(s)) " << " << "
				  << std::setfill('0') << std::setw(2) << GetMinutes(timeVisitor->GetTime()) << ":"
				  << std::setfill('0') << std::setw(2) << GetSeconds(timeVisitor->GetTime()) << std::endl;
		
		album->ForwardVisitor(this);

		delete timeVisitor; timeVisitor = 0;
	}
	catch (std::bad_alloc const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::string const& error)
	{
		std::cerr << "error in PlayVisitor::Visit(Album*): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "PlayVisitor::Visit: Unknown Exception occured" << std::endl;
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
		
		TimeVisitor* timeVisitor = new TimeVisitor;

		musicCollection->Accept(timeVisitor);

		std::cout << "Collection: " << musicCollection->GetName() << " (" << musicCollection->GetNumberOfEntries() << " Song(s)) " 
				  << " << " << std::setfill('0') << std::setw(2) << GetMinutes(timeVisitor->GetTime()) << ":" 
				  << std::setfill('0') << std::setw(2) << GetSeconds(timeVisitor->GetTime()) << std::endl;
		
		musicCollection->ForwardVisitor(this);

		delete timeVisitor; timeVisitor = 0;
	}
	catch (std::bad_alloc const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::string const& error)
	{
		std::cerr << "error in PlayVisitor::Visit(MusicCollection*): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "PlayVisitor::Visit: Unknown Exception occured" << std::endl;
	}
}