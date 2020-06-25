/**
* Entity.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Entity_h
#define Entity_h

#include <list>
#include <iostream>
#include <string>
#include <StringUtils.h>
#include <map>

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
	map<string, string> attributes;

//FUNCTIONS
public:
	Entity();
	~Entity();
	Entity(string name, string description, Entity* parent);

	// pre: --
	// post: searches in elements the Entity of the type and name given by parameter. If it exists, returns the Entity, else returns NULL
	Entity* find(const string &name, const EntityType &type);

	// pre: --
	// post: sets the parent to this entity to the given by parameter
	void changeParentTo(Entity* newParent);

	// pre: --
	// post: shows the name and description of the entity
	virtual void look();

	// pre: --
	// post: adds the pair key value in the attributes map. If it exists already, it overrides it.
	void addAttribute(string key, string value);

	// pre: --
	// post: deletes the pair key value from the attributes map if the key exists in the map.
	void deleteAttribute(string key);

	// pre: --
	// post: searches the value in the attributes map with the given key, if it doesn't exists shows "error".
	// @ deprecated
	string findAttributeValue(string key);

	// pre:--
	// post: returns true if they key exists in the attributes map
	bool hasAttribute(string key);

};

#endif

