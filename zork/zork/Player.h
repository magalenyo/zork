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
#include <time.h> 

class Player : public Character
{
// VARIABLES
public:
protected:
private:
	Item* getBackpack();
	bool enoughInventorySpace() const;
	int calculateChances() const;


//FUNCTIONS
public:
	Player();
	Player(string name, string description, Room *parent);

	void addItem(Item *item);
	void go(const vector<string> &input);
	void take(const vector<string> &input);
	void look() const;
	void inventory() const;
	void unlock(const vector<string> &input);
	void drop(const vector<string> &input);
	void put(const vector<string> &input);
	void throwObject(const vector<string> &input);
	void fight();
	void eat(const vector<string> &input);
	void chances();
	void cross();

	bool isInLastRoom() const;
	bool isWounded();
	bool hasIdol();
	bool isDead();
	
protected:
private:
};

#endif	// Player_h
