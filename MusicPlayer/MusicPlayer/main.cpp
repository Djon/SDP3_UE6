///////////////////////////////////////////////////////////////////////////
// Workfile : Main.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 17.11.2012
// Description : Testdriver for MusicPlayer
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MusicPlayer.h"
#include "MusicFactory.h"
#include "MusicComponent.h"

using namespace std;


void EmptyTestCase()
{
	cout << "Testcase0: Empty testcase with NULL pointer." << endl;

	MusicPlayer* player = new MusicPlayer;
	MusicFactory* fact = new MusicFactory;

	cout << "Add: ";
	player->Add(0);
	cout << " ...done" << endl;

	cout << "GetTime: ";
	player->GetTime(0);
	cout << " ...done" << endl;

	cout << "GetTotalTime: ";
	player->GetTotalTime();
	cout << " ...done" << endl;

	cout << "Play: ";
	player->Play();
	cout << " ...done" << endl;

	cout << "Remove: ";
	player->Remove(0);
	cout << " ...done" << endl;

	cout << "Search: ";
	player->Search("");
	cout << " ...done" << endl;

	cout << "Delete MusicPlayer: ";
	delete player; player=0;
	cout << " ...done" << endl;
	
	cout << "Delete MusicFactory: ";
	delete fact; fact=0;
	cout << " ...done" << endl;
	cout << endl << endl;
}

void NormalTestCase()
{
	cout << "Testcase1: Normal testcase with valid objects." << endl;

	cout << "Create Objects: ";
	MusicPlayer* player = new MusicPlayer;
	MusicFactory* fact = new MusicFactory;

	MusicComponent* Song1 = fact->CreateSong("Staring At The Sun","Americana","The Offspring",132);
	MusicComponent* Song2 = fact->CreateSong("Have You Ever","Americana","The Offspring",236);
	MusicComponent* Song3 = fact->CreateSong("Living In Chaos","Conspiracy Of One","The Offspring",208);
	MusicComponent* Song4 = fact->CreateSong("Psychosocial","All Hope Is Gone","Slipknot",283);

	MusicComponent* Album1 = fact->CreateAlbum("Americana","The Offspring");
	MusicComponent* Album2 = fact->CreateAlbum("Conspiracy Of One","The Offspring");

	MusicComponent* Collection1 = fact->CreateMusicCollection("MyPlayList");
	cout << " ...done" << endl;

	cout << "Put Albums together: ";
	Album1->AddMusic(Song1);
	Album1->AddMusic(Song2);
	Album2->AddMusic(Song3);
	cout << " ...done" << endl;

	cout << "Put an album into an album: ";
	Album1->AddMusic(Album2);
	cout << " ...done" << endl;

	cout << "Put Collection together: ";
	Collection1->AddMusic(Album1);
	Collection1->AddMusic(Song4);
	cout << " ...done" << endl;

	cout << "Put a collection into itself: ";
	Collection1->AddMusic(Collection1);
	cout << " ...done" << endl;


	cout << "Add stuff to the player: ";
	player->Add(Song1);
	player->Add(Collection1);
	player->Add(Album2);
	player->Add(Album1);
	cout << " ...done" << endl;

	cout << "GetTime: ";
	cout << player->GetTime(Song4) << " seconds";
	cout << " ...done" << endl;

	cout << "GetTotalTime: ";
	cout << player->GetTotalTime() << " seconds in player";
	cout << " ...done" << endl;

	cout << "Play: ";
	player->Play();
	cout << " ...done" << endl;

	cout << "Search: ";
	player->Search("in");
	cout << " ...done" << endl;

	cout << "Remove: ";
	player->Remove(Collection1);
	player->Remove(Album1);
	cout << " ...done" << endl;

	cout << "Play after remove: ";
	player->Play();
	cout << " ...done" << endl;

	cout << "Delete MusicPlayer: ";
	delete player; player=0;
	cout << " ...done" << endl;
	
	cout << "Delete MusicFactory: ";
	delete fact; fact=0;
	cout << " ...done" << endl;
	cout << endl << endl;
}

int main()
{
	EmptyTestCase();
	NormalTestCase();

	return 0;
}