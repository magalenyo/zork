#include "Exit.h"

Exit::Exit(string name, string oppositeName, string description, Room* origin, Room* destination) : 
	Entity(name, description, (Entity*) origin),
	locked(false), key(NULL), destination(destination), oppositeName(oppositeName)
{
	this->entityType = EXIT;
	destination->elements.push_back(this);
}

string Exit::getNameFrom(const Room * room) const
{
	if (room == parent)
		return name;
	if (room == destination)
		return oppositeName;

	return name;
}

Room * Exit::getDestinationFrom(const Room * room) const
{
	if (room == parent)
		return destination;
	if (room == destination)
		return (Room*)parent;

	return NULL;
}
