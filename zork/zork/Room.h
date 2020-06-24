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
	//map<string, string> attributes;

public:
	Room();
	Room(string name, string description);

	void addItem(Item *item);
	bool existsInRoom(Entity *entity);
	Exit* getTargetExit(const string &direction) const;

};

#endif

