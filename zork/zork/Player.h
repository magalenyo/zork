/**
* Player.h
*
*
* Created: 20/06/2020
*
* Author: Miguel Ángel Bueno Rivera
*
*/
#ifndef Player_h
#define Player_h

#include "Character.h"
#include <vector>

class Player : public Character
{
// VARIABLES
public:
protected:
private:
	Item* getBackpack();
	bool enoughInventorySpace() const;


//FUNCTIONS
public:
	Player();
	Player(string name, string description, Room *parent);

	void addItem(Item *item);
	void go(const vector<string> &input);
	void take(const vector<string> &input);
	void look() const;
	void inventory() const;
protected:
private:
};

#endif	// Player_h
