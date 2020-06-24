#include "Room.h"

Room::Room()
{

}

Room::Room(string name, string description) : Entity(name, description, NULL)
{
	this->entityType = ROOM;
}
