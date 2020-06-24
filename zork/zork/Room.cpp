#include "Room.h"

Room::Room()
{

}

Room::Room(string name, string description) : Entity(name, description, NULL)
{
	entityType = ROOM;
}

void Room::addItem(Item * item)
{
	elements.push_back((Entity*) item);
}

bool Room::existsInRoom(Entity * entity)
{
	for (Entity *it : elements) {
		if (it->name == entity->name) {
			return true;
		}
	}
	return false;
}

Exit * Room::getTargetExit(const string & direction) const
{
	for (Entity* entity : elements) {
		if (entity->entityType == EXIT) {
			Exit* exit = (Exit*)entity;
			// exit->parent is origin
			if (exit->getNameFrom(this) == direction) {
				return exit;
			}
		}
	}
	return NULL;
}

void Room::addAttribute(string key, string value)
{
	attributes[key] = value;
}

string Room::findAttributeValue(string key)
{
	auto it = attributes.find(key);
	if (it != attributes.end()) {
		return it->second;
	}
	else {
		return "error";
	}
}

bool Room::hasAttribute(string key)
{
	auto it = attributes.find(key);
	return it != attributes.end();
}
