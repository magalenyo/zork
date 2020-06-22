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

/*struct CommandExtended {
	string default;
	string shortcut;

	// pre: --
	// post: returns true if input is equals to default or shortcut
	bool equals(string input);
};*/

class Command {
public:
	string default;

public:
	Command();
	Command(string value);
	virtual bool equals(string input) const;
};

class CommandExtended : public Command {
public:
	string shortcut;

public:
	CommandExtended();
	CommandExtended(string value1, string value2);
	bool equals(string input) const override;
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
	static const Command SAVE;
	static const Command RESTORE;
	static const Command RESTART;
	static const Command VERBOSE;
	static const Command SCORE;
	static const Command DIAGNOSTIC;
	static const Command BRIEF;
	static const Command SUPERBRIEF;
	static const CommandExtended QUIT;
	static const Command CLIMB;
	static const Command G;
	static const Command GO;
	static const Command ENTER;
	static const Command OUT;
	static const CommandExtended HELLO;
	static const Command JUMP;
	static const Command SWEAR;
	static const Command EMPTY;
	static const CommandExtended TAKE;
	static const CommandExtended TAKE_EVERYTHING;
	static const Command THROW;
	static const Command OPEN;
	static const Command READ;
	static const Command DROP;
	static const Command PUT;
	static const Command TURN;
	static const Command MOVE;
	static const Command ATTACK;
	static const Command EXAMINE;
	static const CommandExtended INVENTORY;
	static const Command EAT;
	static const Command SHOUT;
	static const Command CLOSE;
	static const Command TIE;
	static const Command PICK;
	static const Command KILL_SELF;
	static const Command BREAK;
	static const Command KILL;
	static const Command PRAY;
	static const Command DRINK;
	static const Command SMELL;
	static const Command CUT;
	static const Command BAR;
	static const Command LISTEN;
};

#endif //Commands_H