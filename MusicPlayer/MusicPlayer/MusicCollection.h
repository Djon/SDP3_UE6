///////////////////////////////////////////////////////////////////////////
// Workfile : MusicCollection.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Header for MusicCollection.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MUSICCOLLECTION_H
#define MUSICCOLLECTION_H

#include "MusicComponent.h"

class MusicCollection : 
	public MusicComponent
{
public:
	//CTor
	MusicCollection(std::string Name);

	//virtual Destructor
	virtual ~MusicCollection();

	virtual void Accept(Visitor* visitor);	
	void ForwardVisitor(Visitor* visitor);

	virtual TMusicKind GetType();
	size_t GetNumberOfEntries();

	virtual void AddMusic(MusicComponent* m);
private:
	TMusicComponents mMusicComponents;
};
#endif