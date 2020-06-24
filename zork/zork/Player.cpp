#include "Player.h"

Item* Player::getBackpack()
{
	for (Entity* it : elements) {
		if (it->name == "Backpack") {
			return (Item*) it;
		}
	}
	return NULL;
}

bool Player::enoughInventorySpace() const
{
	return elements.size() <= 1;
}

Player::Player()
{
}

Player::Player(string name, string description, Room* parent) : Character(name, description, parent)
{
	this->entityType = PLAYER;
}

void Player::addItem(Item * item)
{
	elements.push_back((Entity*) item);
}

void Player::go(const vector<string>& input)
{
	Exit* targetExit= GetRoom()->getTargetExit(input[1]);
	if (targetExit == NULL) {
		cout << "An exit to '" << input[1] << "' can't be found." << endl;
	}
	else {
		if (targetExit->locked) {
			cout << "The door is locked." << endl;
		}
		else {
			cout << "Going " << input[1] << "\n" << endl;
			changeParentTo(targetExit->getDestinationFrom((Room*)parent));
			parent->look();
		}
	}
}

void Player::take(const vector<string> &input)
{
	if (input.size() == 4) {
		Item* item = (Item*)parent->find(input[3], ITEM);		// checks if the item exists in the source(args[3]) from the room
		if (item == NULL) {
			item = (Item*)find(input[3], ITEM);					// checks if the item exists in the source(args[3]) from the player inventory
		}
		Item* backpack = NULL;
		if (item == NULL) {
			backpack = getBackpack();						// get backpack
			if (backpack != NULL) {
				item = (Item*)backpack->find(input[3], ITEM);	// checks if the item exists in the player backpack
			}
		}

		if (item == NULL) {
			cout << input[3] << " could not be found in the room / inventory" << (backpack != NULL ? " / backpack." : ".") << endl;
			return;
		}
		
		Item* targetItem = (Item*) item->find(input[1], ITEM);

		if (targetItem == NULL) {
			cout << input[1] << " could not be found in " << input[3] << "." << endl;
		}
		else {
			if (enoughInventorySpace()) {						// there's enough room in the inventory
				targetItem->changeParentTo(this);
				cout << item->name << " taken." << endl;
				cout << targetItem->name << " taken from " << input[3] << endl;

			}
			else {
				cout << "Your inventory is full." << (getBackpack() != NULL ? "Try putting your inventory items in your backpack first" : "") << endl;
			}
			
		}
	}
	else if (input.size() == 2) {
		Item* item = (Item*)parent->find(input[1], ITEM);		// checks the item of the world exists in the room
		if (item == NULL) {
			cout << input[1] << " isn't in this room." << endl;
		}
		else {
			if (enoughInventorySpace()) {						// there's enough room in the inventory
				item->changeParentTo(this);
				cout << item->name << " taken." << endl;
			}
			else {
				cout << "Your inventory is full." << (getBackpack() != NULL ? "Try putting your inventory items in your backpack first" : "") << endl;
			}
			
		}
	}
	
}

void Player::look() const
{
	/*if (input.size() > 1) {
		for (Entity* entity : parent->elements) {
			if(entity->name == args[1])
		}
	}
	else {*/
		parent->look();
		for (Entity* entity : parent->elements) {
			if (entity->entityType == ITEM) {
				((Item*) entity)->look();
			}
		}
	//}
}

void Player::inventory() const
{
	
	if (elements.empty()) {
		cout << "Your inventory is empty" << endl;
	}
	else {
		cout << "Your inventory: " << endl;
		for (Entity* item : elements) {
			((Item*) item)->look();
		}
		cout << "----------------" << endl;
	}
}

void Player::unlock(const vector<string>& input)
{
	Exit* targetExit = GetRoom()->getTargetExit(input[1]);
	if (targetExit == NULL) {
		cout << "There was nothing in " << input[1] << "." << endl;
		return;
	}

	if (!targetExit->locked) {
		cout << "The way was already unlocked." << endl;
		return;
	}

	Item* item = (Item*) find(input[3], ITEM);

	if (item == NULL) {
		cout << "Could not find " << input[3] << " in your inventory." << endl;
		return;
	}

	targetExit->unlock();
	cout << "You have unlocked " << targetExit->getNameFrom((Room*)parent) << " with " << input[3] << endl;

	
}
