#ifndef Exit_h
#define Exit_h

#include "Entity.h"
#include "Room.h"
class Exit : public Entity
{
public:
	bool locked;

public:
	Exit(string name, string opposite_name, string description, Room* origin, Room* destination);

};

#endif
