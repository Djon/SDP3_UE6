///////////////////////////////////////////////////////////////////////////
// Workfile : SearchVisitor.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of SearchVisitor
///////////////////////////////////////////////////////////////////////////

#ifndef SEARCHVISITOR_H
#define SEARCHVISITOR_H

#include <string>
#include <list>
#include "Object.h"
#include "Visitor.h"
#include "Song.h"
#include "Album.h"
#include "MusicCollection.h"

class SearchVisitor :
	public Visitor,
	public Object
{
public:
	SearchVisitor(std::string const& name);

	virtual void Visit(Song* song);
	virtual void Visit(Album* album);
	virtual void Visit(MusicCollection* musicCollection);

	TMusicComponents* GetResults();

private:
	std::string mName;
	TMusicComponents mResults;
};

#endif