///////////////////////////////////////////////////////////////////////////
// Workfile : TimeVisitor.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of TimeVisitor
///////////////////////////////////////////////////////////////////////////

#ifndef TIMEVISITOR_H
#define TIMEVISITOR_H

#include "Object.h"
#include "Visitor.h"
#include "Song.h"
#include "Album.h"
#include "MusicCollection.h"

class TimeVisitor :
	public Visitor,
	public Object
{
public:
	TimeVisitor() : mTime(0) {}

	void Visit(Song* song);
	void Visit(Album* album);
	void Visit(MusicCollection* musicCollection);

	size_t GetTime() const;

private:
	size_t mTime;
};

#endif