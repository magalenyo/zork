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

	string getNameFrom(const Room* room) const;
	Room* getDestinationFrom(const Room* room) const;
	void unlock();
};

#endif
