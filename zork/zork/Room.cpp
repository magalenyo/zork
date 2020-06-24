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
