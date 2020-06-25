/**
* Character.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Character_h
#define Character_h

#include "Entity.h"
#include "Room.h"

using namespace std;

class Character : public Entity
{
public:
	Character();
	Character(string name, string description, Room *parent);

	// pre: --
	// post: returns the parent Room
	Room* getRoom() const;
};

#endif
