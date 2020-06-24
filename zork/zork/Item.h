#pragma once
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
	void look() override;
	int getBridgeChance() const;
};

