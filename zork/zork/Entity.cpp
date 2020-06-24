#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

Entity::Entity(string name, string description, Entity* parent) : name(name), description(description), parent(parent)
{
	/*this->name = name;
	this->description = description;
	this->parent = parent;*/

	if (parent != NULL)
		parent->elements.push_back(this);
}

Entity * Entity::find(const string & name, const EntityType &type)
{
	for (Entity* entity : elements) {
		if (entity->entityType == type && StringUtils::toLowerCase(entity->name) == name) {
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

