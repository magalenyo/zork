#include "Character.h"

Character::Character()
{
}

Character::Character(string name, string description, Room* parent) : Entity(name, description, (Entity*) parent)
{
	entityType = CHARACTER;
}

//void Character::go(const vector<string>& input)
//{
//	
//}
