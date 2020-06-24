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

Entity * Entity::find(const string & name, const EntityType &type)
{
	for (Entity* entity : elements) {
		if (entity->name == name && entity->entityType == type) {
			return entity;
		}
	}
	return NULL;
}

void Entity::changeParentTo(Entity * newParent)
{
	if (parent != NULL) {
		parent->elements.remove(this);
	}
	parent = newParent;
	if (parent != NULL) {
		parent->elements.push_back(this);
	}
}

void Entity::look()
{
	cout << name << endl;
	cout << description << endl;
}

//Room * Entity::getParentRoom()
//{
//	return (Room*) parent;
//}
