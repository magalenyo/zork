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
	static const CommandExtended UP;
	static const CommandExtended DOWN;
	static const CommandExtended LOOK;
	static const CommandExtended QUIT;
	static const Command GO;
	static const Command JUMP;
	static const CommandExtended TAKE;
	static const Command THROW;
	static const Command DROP;
	static const Command PUT;
	static const CommandExtended INVENTORY;
	static const Command EAT;
	static const Command PICK;
	static const Command UNLOCK;
	static const Command FIGHT;
	static const Command CHANCES;
	static const Command CROSS;
};

#endif //Commands_H