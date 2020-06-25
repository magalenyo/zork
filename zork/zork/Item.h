/**
* Item.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Item_h
#define Item_h

#include "Entity.h"

enum ItemType {
	WEAPON,
	UTIL,
	CONSUMABLE,
	OBJECTIVE,
	THROWABLE
};

class Item : public Entity
{
public:
	ItemType itemType;
public:
	Item(string name, string description, Entity* parent, ItemType itemType);

	// pre: --
	// post: shows the item and each element of the list elements
	void look() override;

	// pre: --
	// post: returns the chance that needs to be substracted from the total chance of bridge collapse depending on the itemType
	//       weapon: 15
	//		 consumable: 5
	//		 objective: 20
	//		 util: 2
	//       throwable: 10
	int getBridgeChance() const;
};

#endif

