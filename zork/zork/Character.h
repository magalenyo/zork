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

	//void go(const vector<string> &input);
	
};

#endif