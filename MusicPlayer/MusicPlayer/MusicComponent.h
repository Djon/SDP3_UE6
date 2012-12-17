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
#include "TMusicKind.h"

class Visitor;

class MusicComponent : 
	public Object
{
public:
	//virtual Destructor for baseclass
	virtual ~MusicComponent();

	virtual void Accept(Visitor* visitor) = 0;	

	virtual TMusicKind GetType() = 0;
	std::string GetName();
	virtual size_t GetNumberOfEntries() = 0;

	virtual void AddMusic(MusicComponent* m) = 0;
protected:
	std::string mName;
	TMusicKind mType;
};

typedef std::list<MusicComponent*> TMusicComponents;
typedef TMusicComponents::iterator TMusicComponentsItor;

#endif