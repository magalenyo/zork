/**
* Commands.h
*
*
* Created: 21/06/2020
* 
* Author: Miguel Ángel Bueno Rivera
* 
*/

#ifndef Commands_H
#define Commands_H

#include <string>

using namespace std;

struct CommandExtended {
	string default;
	string shortcut;
};

class Commands
{
public:
	static const CommandExtended NORTH;
	static const CommandExtended SOUTH;
	static const CommandExtended EAST;
	static const CommandExtended WEST;
	static const CommandExtended NORTHEAST;
	static const CommandExtended NORTHWEST;
	static const CommandExtended SOUTHEAST;
	static const CommandExtended SOUTHWEST;
	static const CommandExtended UP;
	static const CommandExtended DOWN;
	static const CommandExtended LOOK;
	static const string SAVE;
	static const string RESTORE;
	static const string RESTART;
	static const string VERBOSE;
	static const string SCORE;
	static const string DIAGNOSTIC;
	static const string BRIEF;
	static const string SUPERBRIEF;
	static const CommandExtended QUIT;
	static const string CLIMB;
	static const string G;
	static const string GO;
	static const string ENTER;
	static const string OUT;
	static const CommandExtended HELLO;
	static const string JUMP;
	static const string SWEAR;
	static const string EMPTY;
	static const CommandExtended TAKE;
	static const CommandExtended TAKE_EVERYTHING;
	static const string THROW;
	static const string OPEN;
	static const string READ;
	static const string DROP;
	static const string PUT;
	static const string TURN;
	static const string MOVE;
	static const string ATTACK;
	static const string EXAMINE;
	static const CommandExtended INVENTORY;
	static const string EAT;
	static const string SHOUT;
	static const string CLOSE;
	static const string TIE;
	static const string PICK;
	static const string KILL_SELF;
	static const string BREAK;
	static const string KILL;
	static const string PRAY;
	static const string DRINK;
	static const string SMELL;
	static const string CUT;
	static const string BAR;
	static const string LISTEN;
};

#endif //Commands_H