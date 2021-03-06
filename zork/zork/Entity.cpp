#include "Entity.h"

Entity::Entity()
{
	entityType = ENTITY;
}

Entity::~Entity()
{
}

Entity::Entity(string name, string description, Entity* parent) : name(name), description(description), parent(parent)
{
	entityType = ENTITY;

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

void Entity::addAttribute(string key, string value)
{
	attributes[key] = value;
}

void Entity::deleteAttribute(string key)
{
	attributes.erase(key);
}

string Entity::findAttributeValue(string key)
{
	auto it = attributes.find(key);
	if (it != attributes.end()) {
		return it->second;
	}
	else {
		return "error";
	}
}

bool Entity::hasAttribute(string key)
{
	auto it = attributes.find(key);
	return it != attributes.end();
}


