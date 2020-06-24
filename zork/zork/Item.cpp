#include "Item.h"

Item::Item(string name, string description, Entity * parent, ItemType itemType) : Entity(name, description, parent)
{
	this->entityType = ITEM;
	this->itemType = itemType;
}
