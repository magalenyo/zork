#include "Commands.h"

using namespace std;

const CommandExtended Commands::NORTH = { "north", "n" };
const CommandExtended Commands::SOUTH = { "south", "s" };
const CommandExtended Commands::EAST = { "east", "e" };
const CommandExtended Commands::WEST = { "west", "w" };
const CommandExtended Commands::NORTHEAST = { "northeast", "ne" };
const CommandExtended Commands::NORTHWEST = { "northwest", "nw" };
const CommandExtended Commands::SOUTHEAST = { "southeast", "se" };
const CommandExtended Commands::SOUTHWEST = { "southwest", "sw" };
const CommandExtended Commands::UP = { "up", "u" };
const CommandExtended Commands::DOWN = { "down", "d" };
const CommandExtended Commands::LOOK = { "look", "l" };
const CommandExtended Commands::QUIT = { "quit", "q" };
const CommandExtended Commands::HELLO = { "hi", "hello" };
const CommandExtended Commands::TAKE = { "take", "get" };
const CommandExtended Commands::TAKE_EVERYTHING = { "take all", "get" }; // doubt
const CommandExtended Commands::INVENTORY = { "inventory", "i" };
const Command Commands::SAVE = "save";
const Command Commands::RESTORE = "restore";
const Command Commands::RESTART = "restart";
const Command Commands::VERBOSE = "verbose";
const Command Commands::SCORE = "score";
const Command Commands::DIAGNOSTIC = "diagnostic";
const Command Commands::BRIEF = "brief";
const Command Commands::SUPERBRIEF = "superbrief";
const Command Commands::CLIMB = "climb";
const Command Commands::G = "g";
const Command Commands::GO = "go";
const Command Commands::ENTER = "enter";
const Command Commands::OUT = "out";
const Command Commands::JUMP = "jump";
const Command Commands::SWEAR = "damn";
const Command Commands::EMPTY = "";
const Command Commands::THROW = "throw";
const Command Commands::OPEN = "open";
const Command Commands::READ = "read";
const Command Commands::DROP = "drop";
const Command Commands::PUT = "put";
const Command Commands::TURN = "turn";
const Command Commands::MOVE = "move";
const Command Commands::ATTACK = "attack";
const Command Commands::EXAMINE = "examine";
const Command Commands::EAT = "eat";
const Command Commands::SHOUT = "shout";
const Command Commands::CLOSE = "close";
const Command Commands::TIE = "tie";
const Command Commands::PICK = "pick";
const Command Commands::KILL_SELF = "kill self"; //doubt
const Command Commands::BREAK = "break";
const Command Commands::KILL = "kill";
const Command Commands::PRAY = "pray";
const Command Commands::DRINK = "drink";
const Command Commands::SMELL = "smell";
const Command Commands::CUT = "cut";
const Command Commands::BAR = "bar";
const Command Commands::LISTEN = "listen";
const Command Commands::UNLOCK = "unlock";


// Wand actions are not used

CommandExtended::CommandExtended()
{
	default = "";
	shortcut = "";
}

CommandExtended::CommandExtended(string value1, string value2)
{
	default = value1;
	shortcut = value2;
}


bool CommandExtended::equals(string input) const
{
	return input == default || input == shortcut;
}

Command::Command()
{
	default = "";
}

Command::Command(string value)
{
	default = value;
}

bool Command::equals(string input) const
{
	return default == input;
}
