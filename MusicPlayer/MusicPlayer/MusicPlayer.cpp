///////////////////////////////////////////////////////////////////////////
// Workfile : MusicPlayer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class MusicPlayer
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include "MusicPlayer.h"

void MusicPlayer::Add(MusicComponent* musicComponent)
{
	try
	{
		if(musicComponent == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mMusicComponents.push_back(musicComponent);	//only adds a pointer
	}
	catch (std::string const& error)
	{
		std::cout << "error in MusicPlayer::Add(): " << error << std::endl;
	}
}

size_t MusicPlayer::GetTime(MusicComponent const * const musicComponent)
{
	try
	{
		if(musicComponent == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		
		//check if element is in list
		bool exists = false;
		TMusicComponentsItor itor = mMusicComponents.begin();
		for(; itor != mMusicComponents.end(); ++itor)
		{
			if(itor == musicComponent)
			{
				exists = true;
			}
		}
		if(!exists)
		{
			std::string error = "component doesnt exist in list";
			throw (error); 
		}

		TimeVisitor* timeVisitor = new TimeVisitor();
		musicComponent->Accept(timeVisitor);
		size_t tmp = timeVisitor->GetTime();
		delete timeVisitor;
		
		return tmp;
	}
	catch (std::string const& error)
	{
		std::cout << "error in MusicPlayer::GetTime(): " << error << std::endl;
	}
	catch (std::bad_alloc const& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

size_t MusicPlayer::GetTotalTime()
{
	try
	{
		TimeVisitor* timeVisitor = new TimeVisitor();
		
		TMusicComponentsItor itor = mMusicComponents.begin();
		for(; itor != mMusicComponents.end(); ++itor)
		{
			itor->Accept(timeVisitor);
		}

		size_t tmp = timeVisitor->GetTime();
		delete timeVisitor;
		return tmp;
	}
	catch (std::bad_alloc const& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

void MusicPlayer::Play()
{
	try
	{
		PlayVisitor* playVisitor = new PlayVisitor();

		TMusicComponentsItor itor = mMusicComponents.begin();
		for(; itor != mMusicComponents.end(); ++itor)
		{
			itor->Accept(playVisitor);
		}

		delete playVisitor; playVisitor = 0;
	}
	catch (std::bad_alloc const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void MusicPlayer::Remove(MusicComponent const * const musicComponent)
{
	try
	{
		if(musicComponent == 0)
		{
			std::string error = "no valid pointer";
			throw (error); 
		}
		mMusicComponents.remove(musicComponent);	//only deletes the pointer, not the object
	}
	catch (std::string const& error)
	{
		std::cout << "error in MusicPlayer::Remove(): " << error << std::endl;
	}
}

void MusicPlayer::Search(std::string const& name)
{
	try
	{
		if(name == "")
		{
			std::string error = "no valid name";
			throw (error); 
		}

		std::cout << "found medias: (search for \"" << name << "\")" << std::endl;
		
		SearchVisitor* searchVisitor = new SearchVisitor(name);

		TMusicComponentsItor itor = mMusicComponents.begin();
		for(; itor != mMusicComponents.end(); ++itor)
		{
			itor->Accept(searchVisitor);
		}
		
		TMusicComponents* tmp;
		tmp = searchVisitor->GetResults();
		
		itor = tmp->begin();
		for(; itor != tmp->end(); ++itor)
		{
			std::cout << tmp->GetName() << std::endl;
		}
		
		delete searchVisitor; searchVisitor = 0;
	}
	catch (std::string const& error)
	{
		std::cout << "error in MusicPlayer::Search(): " << error << std::endl;
	}
}