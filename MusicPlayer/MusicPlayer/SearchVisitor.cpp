///////////////////////////////////////////////////////////////////////////
// Workfile : SearchVisitor.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class SearchVisitor
///////////////////////////////////////////////////////////////////////////

#include "SearchVisitor.h"

SearchVisitor::SearchVisitor(std::string const& name)
{
}

void SearchVisitor::Visit(Song*)
{
}

void SearchVisitor::Visit(Album*)
{
}

void SearchVisitor::Visit(MusicCollection*)
{
}

TMusicComponents* SearchVisitor::GetResults()
{
}