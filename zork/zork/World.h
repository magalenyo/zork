/**
* World.h
*
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
	UNKNOWN,
	FINISHED
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

	// pre: input is a vector of lowercase strings
	// post: processes the command passed as input and returns a result depending on how it performed
	ResultEnum parseCommand(vector<string> input);

	// pre: --
	// post: shows the ending
	void finishGame();
protected:
private:

};


#endif //World_H


