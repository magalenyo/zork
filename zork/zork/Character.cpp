#include "Character.h"

Character::Character()
{
}

Character::Character(string name, string description, Room* parent) : Entity(name, description, (Entity*) parent)
{
	entityType = CHARACTER;
}

Room * Character::GetRoom() const
{
	return (Room*)parent;
}

//void Character::go(const vector<string>& input)
//{
//	
//}
