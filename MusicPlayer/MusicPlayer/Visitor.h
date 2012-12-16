///////////////////////////////////////////////////////////////////////////
// Workfile : Visitor.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Interface for Visitors
///////////////////////////////////////////////////////////////////////////

#ifndef VISITOR_H
#define VISITOR_H

class Song;
class Album;
class MusicCollection;

class Visitor
{
public:
	//virtual Destructor
	virtual ~Visitor() {};

	virtual void Visit(Song* song) = 0;
	virtual void Visit(Album* album) = 0;
	virtual void Visit(MusicCollection* musicCollection) = 0;
};

#endif