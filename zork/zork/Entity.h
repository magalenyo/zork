/**
* Entity.h
*
*
* Created: 20/06/2020
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Entity_h
#define Entity_h

#include <vector>
#include <string>

using namespace std;

enum EntityType {
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CHARACTER,
	PLAYER
};

class Entity
{
// VARIABLES
public:
	vector<Entity*> elements;
	string name;
	string description;
	EntityType entityType;
	Entity *parent;

//FUNCTIONS
public:
	Entity();
	Entity(string name, string description, Entity* parent);
	//Room* getParentRoom();
protected:
private:

};

#endif

