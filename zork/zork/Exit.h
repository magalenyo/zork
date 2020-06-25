/**
* Exit.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Exit_h
#define Exit_h

#include "Entity.h"
#include "Room.h"
#include <string>

class Room;

using namespace std;

class Exit : public Entity
{
public:
	bool locked;
	bool blocked;
	Room* destination;
	string oppositeName;
	Entity* key;

public:
	Exit(string name, string oppositeName, string description, Room* origin, Room* destination);

	// pre: --
	// post: if the parent Room (origin) is the passed as parameter, returns the name, if the parmeter is the destination returns the opposite name
	string getNameFrom(const Room* room) const;

	// pre: --
	// post: if the parent Room (origin) is the passed as parameter, returns the destination room, if the parmeter is the destination returns the parent room
	Room* getDestinationFrom(const Room* room) const;

	// pre: --
	// post: sets locked to false
	void unlock();
};

#endif
