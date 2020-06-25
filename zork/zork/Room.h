/**
* Room.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Room_h
#define Room_h

#include "Entity.h"
#include "Item.h"
#include "Exit.h"
#include <map>

class Exit;	// needed otherwise error

using namespace std;

class Room : public Entity
{
public:
	Room();
	Room(string name, string description);

	// pre: --
	// post: adds the passed Item and puts into the list elements
	void addItem(Item *item);

	// pre: --
	// post: returns true if it has an element of the list elements that has the same name as the entity passed
	bool existsInRoom(Entity *entity);

	// pre: --
	// post: returns the Exit of the given direction of the list elements (depending on how the Exists are positioned), if it doesn't exist returns NULL
	Exit* getTargetExit(const string &direction) const;
};

#endif

