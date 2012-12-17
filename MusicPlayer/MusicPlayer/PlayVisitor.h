///////////////////////////////////////////////////////////////////////////
// Workfile : PlayVisitor.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of PlayVisitor.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef PLAYVISITOR_H
#define PLAYVISITOR_H

#include "Object.h"
#include "Visitor.h"
#include "Song.h"
#include "Album.h"
#include "MusicCollection.h"

class PlayVisitor :
	public Visitor,
	public Object
{
public:
	virtual void Visit(Song* song);
	virtual void Visit(Album* album);
	virtual void Visit(MusicCollection* musicCollection);
	PlayVisitor();
private:
	int GetMinutes(size_t const seconds);
	int GetSeconds(size_t const seconds);
	int mCounter;
};

#endif