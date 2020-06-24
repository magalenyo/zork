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

#include <list>
#include <iostream>
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
	string name;
	string description;
	EntityType entityType;

	list<Entity*> elements;
	Entity *parent;

//FUNCTIONS
public:
	Entity();
	Entity(string name, string description, Entity* parent);

	Entity* find(const string &name, const EntityType &type);
	void changeParentTo(Entity* newParent);

	virtual void look();
	//Room* getParentRoom();
protected:
private:

};

#endif

