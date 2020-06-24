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

