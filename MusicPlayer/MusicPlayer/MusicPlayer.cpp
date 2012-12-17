///////////////////////////////////////////////////////////////////////////
// Workfile : MusicPlayer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class MusicPlayer
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <iterator>
#include "MusicPlayer.h"
#include "TimeVisitor.h"
#include "SearchVisitor.h"
#include "PlayVisitor.h"

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
		std::cerr << "error in MusicPlayer::Add(): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "MusicPlayer::Add: Unknown Exception occured" << std::endl;
	}
}

size_t MusicPlayer::GetTime(MusicComponent * const musicComponent)
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

		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=,&exists](MusicComponent* m)
		{
			if(m == musicComponent)
			{
				exists = true;
			}
		});
		if(!exists)
		{
			std::string error = "component doesnt exist in list";
			throw (error); 
		}

		TimeVisitor* timeVisitor = new TimeVisitor;
		musicComponent->Accept(timeVisitor);
		size_t tmp = timeVisitor->GetTime();
		delete timeVisitor;

		return tmp;
	}
	catch (std::bad_alloc const& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	catch (std::string const& error)
	{
		std::cout << "error in MusicPlayer::GetTime(): " << error << std::endl;
		return 0;
	}
	catch(...)
	{
		std::cerr << "MusicPlayer::GetTime: Unknown Exception occured" << std::endl;
		return 0;
	}
}

size_t MusicPlayer::GetTotalTime()
{
	try
	{
		TimeVisitor* timeVisitor = new TimeVisitor;

		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=](MusicComponent* m)
		{
			m->Accept(timeVisitor);
		});

		size_t tmp = timeVisitor->GetTime();
		delete timeVisitor;
		return tmp;
	}
	catch (std::bad_alloc const& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	catch(...)
	{
		std::cerr << "MusicPlayer::GetTotalTime: Unknown Exception occured" << std::endl;
		return 0;
	}
}

void MusicPlayer::Play()
{
	try
	{
		PlayVisitor* playVisitor = new PlayVisitor;

		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=](MusicComponent* m)
		{
			m->Accept(playVisitor);
		});

		delete playVisitor; playVisitor = 0;
	}
	catch (std::bad_alloc const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "MusicPlayer::Play: Unknown Exception occured" << std::endl;
	}
}

void MusicPlayer::Remove(MusicComponent * const musicComponent)
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
		std::cerr << "error in MusicPlayer::Remove(): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "MusicPlayer::Remove: Unknown Exception occured" << std::endl;
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

		std::for_each(mMusicComponents.begin(),mMusicComponents.end(),[=](MusicComponent* m)
		{
			m->Accept(searchVisitor);
		});

		TMusicComponents* tmp;
		tmp = searchVisitor->GetResults();

		std::for_each(tmp->begin(),tmp->end(),[=](MusicComponent* m)
		{
			std::cout << m->GetName() << std::endl;
		});

		delete searchVisitor; searchVisitor = 0;
	}
	catch (std::bad_alloc const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::string const& error)
	{
		std::cerr << "error in MusicPlayer::Search(): " << error << std::endl;
	}
	catch(...)
	{
		std::cerr << "MusicPlayer::Search: Unknown Exception occured" << std::endl;
	}
}