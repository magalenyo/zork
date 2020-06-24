#ifndef Room_h
#define Room_h

#include "Entity.h"
#include "Item.h"

using namespace std;

class Room : public Entity
{
public:
	Room();
	Room(string name, string description);

	void addItem(Item *item);
	bool existsInRoom(Entity *entity);
};

#endif

