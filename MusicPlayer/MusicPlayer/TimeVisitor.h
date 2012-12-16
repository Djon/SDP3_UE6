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
	TimeVisitor();

	virtual void Visit(Song* song) const;
	virtual void Visit(Album* album) const;
	virtual void Visit(MusicCollection* musicCollection) const;

	size_t GetTime() const;

private:
	size_t mTime;
};

#endif