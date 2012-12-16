///////////////////////////////////////////////////////////////////////////
// Workfile : MusicComponent.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 16.12.2012
// Description : Header for MusicComponent.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MUSICCOMPONENT_H
#define MUSICCOMPONENT_H

#include <list>
#include <string>
#include "Object.h"
#include "Visitor.h"

class MusicComponent : 
	public Object
{
public:
	//virtual Destructor for baseclass
	virtual ~MusicComponent();

	virtual void Accept(Visitor* visitor) = 0;	
	virtual void Play() = 0;

	std::string GetName(); 
protected:
	std::string mName;
};

typedef std::list<MusicComponent*> MusicList;

#endif