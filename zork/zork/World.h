/**
* world.h
*
*
* Created: 20/06/2020
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef World_h
#define World_h

#include <iostream>
#include <vector>
#include <Entity.h>
#include <Player.h>
#include <Exit.h>
#include <Item.h>
#include <Commands.h>


using namespace std;

enum ResultEnum {
	OK,
	QUIT,
	UNKNOWN
};

class World
{
// VARIABLES
public:
protected:
private:
	vector<Entity*> entities;
	Player* player;

//FUNCTIONS
public:
	World();
	ResultEnum parseCommand(vector<string> input);
	bool isEndCommand(const vector<string> &input);
protected:
private:

};


#endif //World_H


