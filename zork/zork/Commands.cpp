#include "Commands.h"

using namespace std;

const struct CommandExtended Commands::NORTH = { "north", "n" };
const struct CommandExtended Commands::SOUTH = { "south", "s" };
const struct CommandExtended Commands::EAST = { "east", "e" };
const struct CommandExtended Commands::WEST = { "west", "w" };
const struct CommandExtended Commands::NORTHEAST = { "northeast", "ne" };
const struct CommandExtended Commands::NORTHWEST = { "northwest", "nw" };
const struct CommandExtended Commands::SOUTHEAST = { "southeast", "se" };
const struct CommandExtended Commands::SOUTHWEST = { "southwest", "sw" };
const struct CommandExtended Commands::UP = { "up", "u" };
const struct CommandExtended Commands::DOWN = { "down","d" };
const struct CommandExtended Commands::LOOK = { "look","l" };
const string Commands::SAVE = "save";
const string Commands::RESTORE = "restore";
const string Commands::RESTART = "restart";
const string Commands::VERBOSE = "verbose";
const string Commands::SCORE = "score";
const string Commands::DIAGNOSTIC = "diagnostic";
const string Commands::BRIEF = "brief";
const string Commands::SUPERBRIEF = "superbrief";
const struct CommandExtended Commands::QUIT = { "quit","q" };
const string Commands::CLIMB = "climb";
const string Commands::G = "g";
const string Commands::GO = "go";
const string Commands::ENTER = "enter";
const string Commands::OUT = "out";
const struct CommandExtended Commands::HELLO = { "hi","hello" };
const string Commands::JUMP = "jump";
const string Commands::SWEAR = "damn";
const string Commands::EMPTY = "";
const struct CommandExtended Commands::TAKE = { "take","get" };
const struct CommandExtended Commands::TAKE_EVERYTHING = { "take all", "get" };			// doubt
const string Commands::THROW = "throw";
const string Commands::OPEN = "open";
const string Commands::READ = "read";
const string Commands::DROP = "drop";
const string Commands::PUT = "put";
const string Commands::TURN = "turn";
const string Commands::MOVE = "move";
const string Commands::ATTACK = "attack";
const string Commands::EXAMINE = "examine";
const struct CommandExtended Commands::INVENTORY = { "inventory","i" };
const string Commands::EAT = "eat";
const string Commands::SHOUT = "shout";
const string Commands::CLOSE = "close";
const string Commands::TIE = "tie";
const string Commands::PICK = "pick";
const string Commands::KILL_SELF = "kill self";			//doubt
const string Commands::BREAK = "break";
const string Commands::KILL = "kill";
const string Commands::PRAY = "pray";
const string Commands::DRINK = "drink";
const string Commands::SMELL = "smell";
const string Commands::CUT = "cut";
const string Commands::BAR = "bar";
const string Commands::LISTEN = "listen";

// Wand actions are not used