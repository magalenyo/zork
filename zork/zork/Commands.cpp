#include "Commands.h"

using namespace std;

const CommandExtended Commands::NORTH = { "north", "n" };
const CommandExtended Commands::SOUTH = { "south", "s" };
const CommandExtended Commands::EAST = { "east", "e" };
const CommandExtended Commands::WEST = { "west", "w" };
const CommandExtended Commands::UP = { "up", "u" };
const CommandExtended Commands::DOWN = { "down", "d" };
const CommandExtended Commands::LOOK = { "look", "l" };
const CommandExtended Commands::QUIT = { "quit", "q" };
const CommandExtended Commands::TAKE = { "take", "get" };
const CommandExtended Commands::INVENTORY = { "inventory", "i" };
const Command Commands::GO = "go";
const Command Commands::THROW = "throw";
const Command Commands::DROP = "drop";
const Command Commands::PUT = "put";
const Command Commands::EAT = "eat";
const Command Commands::PICK = "pick";
const Command Commands::UNLOCK = "unlock";
const Command Commands::FIGHT = "fight";
const Command Commands::CHANCES = "chances";
const Command Commands::CROSS = "cross";


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
