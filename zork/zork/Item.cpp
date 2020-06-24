#include "Item.h"

Item::Item(string name, string description, Entity * parent, ItemType itemType) : Entity(name, description, parent)
{
	this->entityType = ITEM;
	this->itemType = itemType;
}

void Item::look()
{
	//Entity::look();
	cout << "- " << name << ". " << description << endl;
	if (!elements.empty()) {
		cout << "-> Content of " << name << ":" << endl;
		for (Entity* entity : elements) {
			cout << "   "; ((Item*)entity)->look();
		}
	}
	
}

int Item::getBridgeChance() const
{
	int chance = 0;
	switch(itemType) {
		case WEAPON:
			chance = 15;
			break;
		case CONSUMABLE:
			chance = 5;
			break;
		case OBJECTIVE:
			chance = 20;
			break;
		case UTIL:
			chance = 2;
		default:			// throwable
			chance = 10;
			break;
	}
	return chance;
}

