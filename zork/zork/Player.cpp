#include "Player.h"

//void Player::go() 
//{
//}

Player::Player()
{
}

Player::Player(string name, string description, Room * parent) : Character(name, description, parent)
{
	this->entityType = PLAYER;
}
