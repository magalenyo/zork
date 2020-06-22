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

using namespace std;

class World
{
// VARIABLES
public:
protected:
private:
	vector<Entity> _entities;
	Player _player;

//FUNCTIONS
public:
	World();
protected:
private:

};


#endif //World_H


