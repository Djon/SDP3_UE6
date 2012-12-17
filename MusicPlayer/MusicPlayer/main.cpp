///////////////////////////////////////////////////////////////////////////
// Workfile : Main.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 17.11.2012
// Description : Testdriver for MusicPlayer
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MusicPlayer.h"

using namespace std;


void EmptyTestCase()
{
	cout << "Testcase0: Empty testcase with NULL pointer." << endl;

	MusicPlayer* player = new MusicPlayer;

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
	player->Search(0);
	cout << " ...done" << endl;

	cout << "Delete MusicPlayer: ";
	delete player; player=0;
	cout << " ...done" << endl;
	cout << endl << endl;
}

int main()
{
	EmptyTestCase();


	return 0;
}