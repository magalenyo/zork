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
	Exit* targetExit= getRoom()->getTargetExit(input[1]);
	if (targetExit == NULL) {
		cout << "An exit to '" << input[1] << "' can't be found." << endl;
	}
	else {
		if (targetExit->locked) {
			cout << "The door is locked." << endl;
		}
		else if (targetExit->blocked) {
			cout << "The path is blocked." << endl;
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
				cout << targetItem->name << " taken from " << input[3] << endl;
				targetItem->changeParentTo(this);
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
	Exit* targetExit = getRoom()->getTargetExit(input[1]);
	if (targetExit == NULL) {
		cout << "There was no exist called " << input[1] << "." << endl;
		return;
	}

	if (!targetExit->locked) {
		cout << "The way was already unlocked." << endl;
		return;
	}

	Item* item = (Item*) find(input[3], ITEM);

	Item* backpack = NULL;
	if (item == NULL) {
		backpack = getBackpack();						// get backpack
		if (backpack != NULL) {
			item = (Item*)backpack->find(input[3], ITEM);	// checks if the item exists in the player backpack
		}
	}

	if (item == NULL) {
		cout << "Could not find " << input[3] << " in your inventory." << endl;
		return;
	}

	targetExit->unlock();
	cout << "You have unlocked " << targetExit->getNameFrom((Room*)parent) << " with " << input[3] << "." << endl;
	parent->description = "The door is open.";
}

void Player::drop(const vector<string>& input)
{
	if (input.size() == 2) {
		Room* currentRoom = getRoom();
		
		Item* item = (Item*)find(input[1], ITEM);

		Item* backpack = NULL;
		if (item == NULL) {
			backpack = getBackpack();						// get backpack
			if (backpack != NULL) {
				item = (Item*)backpack->find(input[1], ITEM);	// checks if the item exists in the player backpack
			}
		}

		if (item == NULL) {
			cout << input[1] << " could not be found in the inventory" << (backpack != NULL ? " / backpack." : ".") << endl;
			return;
		}

		cout << "You just dropped " << input[1] << "." << endl;
		item->changeParentTo(parent);
	}
}

void Player::put(const vector<string>& input)
{
	if (input[1] == input[3]) {										// put backpack into backpack?
		cout << "Please, don't do that." << endl;
		return;
	}

	Item* item = (Item*)find(input[1], ITEM);						// find first item

	Item* backpack = NULL;
	if (item == NULL) {
		backpack = getBackpack();
		if (backpack != NULL) {
			item = (Item*)backpack->find(input[1], ITEM);			// checks if the item exists in the player backpack
		}
	}

	if (item == NULL) {												// if not found in backpack
		item = (Item*)parent->find(input[1], ITEM);					// find in room
	}

	if (item == NULL) {												// if not found in backpack or inventory
		cout << input[1] << " could not be found in the room / inventory" << (getBackpack() != NULL ? " / backpack." : ".") << endl;
		return;
	}

	//--- If this point reached, the first item has been found

	Item* placeToPut = (Item*)find(input[3], ITEM);					// find in inventory

	if (placeToPut == NULL) {										// if not found in inventory,. find in backpack
		/*backpack = getBackpack();*/
		if (backpack != NULL) {
			placeToPut = (Item*)backpack->find(input[1], ITEM);		// checks if the item exists in the player backpack
		}
	}

	if (placeToPut == NULL) {										// if not found in backpack
		placeToPut = (Item*) parent->find(input[3], ITEM);			// find in room
	}

	if (placeToPut == NULL) {										// if not found in room, backpack or inventory
		cout << input[3] << " could not be found in the room / inventory" << (getBackpack() != NULL ? " / backpack." : ".") << endl;
		return;
	}

	cout << "You just put " << input[1] << " into " << input[3] << "." << endl;
	item->changeParentTo(placeToPut);

}

void Player::throwObject(const vector<string>& input)
{
	Item* item = (Item*)find(input[1], ITEM);
	Item* backpack = NULL;
	if (item == NULL) {
		backpack = getBackpack();
		if (backpack != NULL) {
			item = (Item*)backpack->find(input[1], ITEM);			// checks if the item exists in the player backpack
		}
	}
	if (item == NULL) {
		cout << input[1] << " could not be found in the inventory" << (getBackpack() != NULL ? " / backpack." : ".") << endl;
		return;
	}

	if (item->itemType != THROWABLE) {
		cout << input[1] << " cannot be thrown." << endl;
		return;
	}

	if (getRoom()->hasAttribute("wolves")) {
		cout << "You throw away the rock and the wolves leave. The path is no longer blocked." << endl;
		item->changeParentTo(NULL);
		getRoom()->name = "No more wolves.";
		getRoom()->description = "The path is now clear. You can now go north to the temple.";
		Exit* targetExit = getRoom()->getTargetExit("north");
		targetExit->blocked = false;
	}
	else {
		cout << "There's no one here, I shouldn't throw the rock" << endl;
	}
}

bool Player::isInLastRoom() const
{
	return getRoom()->hasAttribute("end");
}

bool Player::hasIdol()
{
	Item* item = (Item*)find("idol", ITEM);

	Item* backpack = NULL;
	if (item == NULL) {
		backpack = getBackpack();							// get backpack
		if (backpack != NULL) {
			item = (Item*)backpack->find("idol", ITEM);		// checks if the item exists in the player backpack
		}
	}

	return item != NULL;
}
