#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(string name, string description, Entity* parent) : name(name), description(description), parent(parent)
{
	this->name = name;
	this->description = description;
	this->parent = parent;
}

//Room * Entity::getParentRoom()
//{
//	return (Room*) parent;
//}
