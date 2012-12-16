///////////////////////////////////////////////////////////////////////////
// Workfile : Visitor.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Interface for Visitors
///////////////////////////////////////////////////////////////////////////

#ifndef VISITOR_H
#define VISITOR_H

#include "Song.h"
#include "Album.h"
#include "MusicCollection.h"

class Visitor
{
public:
	//virtual Destructor
	virtual ~Visitor();

	virtual void Visit(Song* song) const = 0;
	virtual void Visit(Album* album) const = 0;
	virtual void Visit(MusicCollection* musicCollection) const = 0;
	
};

#endif