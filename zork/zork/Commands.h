/**
* Commands.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef Commands_h
#define Commands_h

#include <string>

using namespace std;

// Default command, has only one value: default
class Command {
public:
	string default;

public:
	Command();
	Command(string value);

	// pre: --
	// post: returns true if input equals default
	virtual bool equals(string input) const;
};

// Extended Command, has an extra value: shortcut
class CommandExtended : public Command {
public:
	string shortcut;

public:
	CommandExtended();
	CommandExtended(string value1, string value2);

	//pre: --
	//post: returns true if input equals default or input equals shortcut
	bool equals(string input) const override;
};

// Static class with the commands
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