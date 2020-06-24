#include "Exit.h"

Exit::Exit(string name, string opposite_name, string description, Room* origin, Room* destination) : 
	Entity(name, description, (Entity*) origin),
	locked(false)
{
	this->entityType = EXIT;
}
