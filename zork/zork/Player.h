/**
* Player.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/
#ifndef Player_h
#define Player_h

#include "Character.h"
#include <vector>
#include <time.h> 

class Player : public Character
{
// VARIABLES
private:
	// pre: --
	// post: if the user has the backpack in the inventory, returns the reference to it
	Item* getBackpack();

	// pre: --
	// post: returns true if the user has less than 2 items in the inventory
	bool enoughInventorySpace() const;

	// pre: --
	// post: returns the sum of the chances of the elements of the inventory
	int calculateChances() const;


//FUNCTIONS
public:
	Player();
	Player(string name, string description, Room *parent);

	// pre: --
	// post: adds item to the elements list
	void addItem(Item *item);

	// pre: --
	// post: if the exit to the input[1] direction exists and if it's not blocked or locked, moves the player to that room (changes the parent to the new room) and executes "look"
	void go(const vector<string> &input);

	// pre: --
	// post: if input has 2 positions, takes the item input[1] if exists from the room if it exists and adds it to the inventory if available (the inventory is not full, full -> 2 items)
	//       if input has 4 position, tkaes the item input[1] if exists from the input [3] if exists and adds it to the inventory if available (the inventory is not full, full -> 2 items)
	void take(const vector<string> &input);

	// pre: --
	// post: shows the name and description of room and the name and description of the elements in the room
	void look() const;

	// pre: --
	// post: shows the inventory. Prints all the elements of the Player and if an item has elements, prints them too
	void inventory() const;

	// pre: --
	// post: takes the exit input[1] if exists and takes the item [3] if exists and unlocks the exit
	void unlock(const vector<string> &input);

	// pre: --
	// post: drops the item input[1] if exists into the room
	void drop(const vector<string> &input);

	// pre: --
	// post: if input[1] and input[3] are different, takes the item input[1] if exists and puts it into the item input[3] if exists (changes parents)
	void put(const vector<string> &input);

	// pre: --
	// post: if the player has the item input[1] and is in the room of the wolves and the item is throwable, unlocks the exit to the temple.
	void throwObject(const vector<string> &input);

	// pre: --
	// post: if the user has a sword and is in the wolves room, unblocks the exit to the temple and adds the attribute wounded to the player
	void fight();

	// pre: --
	// post: searches in elements the Item that has the same name as input 1 and if exists, consumes it and heals the player removing the attribute wounded
	void eat(const vector<string> &input);

	// pre: --
	// post: if the player is in the room of the bridge, shows the chances of crossing the bridge with the current equipment of the player
	void chances();

	// pre: --
	// post: if the player is in the room of the bridge, with the chances of crossing the bridge, generates a random number and
	//       if it's in the safe zone of the chance, unblocks the exit to the temple and moves the player directly to the temple
	void cross();

	/**************************************************************/

	// pre: --
	// post: returns true if the parent Room has the attribute "end"
	bool isInLastRoom() const;

	// pre: --
	// post: returns true if the player has the attribute "wounded"
	bool isWounded();

	// pre: --
	// post: returns true if the player has the idol in the inventory or in the backpack
	bool hasIdol();

	// pre: --
	// post: returns true if the player has the attribute "dead" (the river killed it)
	bool isDead();
	
};

#endif	// Player_h
