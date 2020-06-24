#include "World.h"

World::World()
{
	// Rooms
	Room* crossroad = new Room("Crossroad","You're at a crossroad and you can take two different paths, to the west or the east. You can hear growls coming from the east path.");
	Room* westPath = new Room("West path", "You see what appears to be an empty house on the west and a road to the north.");
	Room* road = new Room("Road", "The road is a dead end, but you see a treehouse you can climb.");
	Room* treehouse = new Room("Treehouse", "You've climbed up to the treehouse. In the distance, you can see the temple.");
	Room* entrance = new Room("House entrance", "You're at the entrance and you knock, but there's no answer. The door is locked and facing west.");
	Room* house = new Room("House", "You finally got into the house");
	Room* eastPath = new Room("East path", "Two wolves are blocking the path. You see an alternative path heading east: a damaged bridge over a furious river.");
	Room* wolves = new Room("Wolves!", "You're in front of two fierce wolves, what are you going to do?");
	      wolves->addAttribute("wolves", "true");
	Room* bridge = new Room("The damaged bridge", "You can take your chances and cross the bridge, but it doesn't look safe.");
	Room* end = new Room("Sacred temple", "You finally reached the temple! You are pleasently welcome by the monks.");

	entities.push_back(crossroad);
	entities.push_back(westPath);
	entities.push_back(road);
	entities.push_back(treehouse);
	entities.push_back(entrance);
	entities.push_back(house);
	entities.push_back(eastPath);
	entities.push_back(wolves);
	entities.push_back(bridge);
	entities.push_back(end);


	//Exits
	Exit* crossroadToWestPath = new Exit("west", "east", "To the west path", crossroad, westPath);
	Exit* westPathToRoad = new Exit("north", "south", "Down the road", westPath, road);
	Exit* roadToTreehouse = new Exit("up", "down", "Up the treehouse", road, treehouse);
	Exit* westPathToEntrance = new Exit("west", "east", "Entrance", westPath, entrance);
	Exit* entranceToHouse = new Exit("west", "east", "To House", entrance, house);
		  entranceToHouse->locked = true;
	Exit* crossroadToEastPath = new Exit("east", "west", "To the east path", crossroad, eastPath);
	Exit* eastPathToWolves= new Exit("north", "south", "To wolves path", eastPath, wolves);
	Exit* wolvesPathToEnd = new Exit("north", "south", "To the temple", wolves, end);
		  wolvesPathToEnd->blocked = true;
	Exit* eastPathToBridge = new Exit("east", "west", "Bridge path", eastPath, bridge);
	Exit* bridgePathToEnd = new Exit("north", "south", "To the temple", bridge, end);

	entities.push_back(crossroadToWestPath);
	entities.push_back(westPathToRoad);
	entities.push_back(roadToTreehouse);
	entities.push_back(westPathToEntrance);
	entities.push_back(entranceToHouse);
	entities.push_back(crossroadToEastPath);
	entities.push_back(eastPathToWolves);
	entities.push_back(wolvesPathToEnd);
	entities.push_back(eastPathToBridge);
	entities.push_back(bridgePathToEnd);

	player = new Player("Player", "You're a braverous explorer. Your mission is to find your way to the temple to deliver the idol.", crossroad);

	//Items
	Item* goldenIdol = new Item("Idol", "This is the sacred idol, small but heavy, and most importantly, GOLDEN!", player, OBJECTIVE);
	Item* key = new Item("Key", "This is the key to the house, looks old and rusty.", treehouse, UTIL);
	Item* berries = new Item("Berries", "Juicy berries.", road, CONSUMABLE);
	Item* sword = new Item("Sword", "A nice and sharp sword.", house, WEAPON);
	Item* rock = new Item("Rock", "Just a regular rock. This can make some noise and distract.", westPath, THROWABLE);
	Item* backpack = new Item("Backpack", "With it, you can carry more objects.", treehouse, UTIL);
	Item* coins = new Item("Coins", "Shiny golden coins.", bridge, UTIL);
	// add sign?

	entities.push_back(goldenIdol);
	entities.push_back(key);
	entities.push_back(berries);
	entities.push_back(sword);
	entities.push_back(rock);
	entities.push_back(backpack);
	entities.push_back(coins);

	// Characters
	Character* wolf1 = new Character("A big wolf", "This wolf has razor sharp teeth.", wolves);
	Character* wolf2 = new Character("A smaller wolf", "Not so threatening, but still dangerous.", wolves);
	
	//player->addItem(goldenIdol);
	/*goldenIdol->elements.push_back(key);
	key->elements.push_back(sword);
	player->addItem(rock);*/
	
	entities.push_back(wolf1);
	entities.push_back(wolf2);
	entities.push_back(player);
	
	player->look();
}

ResultEnum World::parseCommand(vector<string> input)
{
	switch (input.size()) {
		case 0:
			return UNKNOWN;
			break;
		case 1:
			if (Commands::NORTH.equals(input[0])){
				input.push_back("north");
				player->go(input);
			}
			else if (Commands::SOUTH.equals(input[0])) {
				input.push_back("south");
				player->go(input);
			}
			else if (Commands::EAST.equals(input[0])) {
				input.push_back("east");
				player->go(input);
			}
			else if (Commands::WEST.equals(input[0])) {
				input.push_back("west");
				player->go(input);
			}
			else if (Commands::UP.equals(input[0])) {
				input.push_back("up");
				player->go(input);
			}
			else if (Commands::DOWN.equals(input[0])) {
				input.push_back("down");
				player->go(input);
			}
			else if (Commands::LOOK.equals(input[0])) {
				player->look();
			}
			else if (Commands::INVENTORY.equals(input[0])) {
				player->inventory();
			}
			else {
				cout << "I could not understand the last command." << endl;
			}
			break;
		case 2:
			if (Commands::GO.equals(input[0])) {
				player->go(input);
			}
			else if (Commands::TAKE.equals(input[0]) || Commands::PICK.equals(input[0])) {
				player->take(input);
			}
			else if (Commands::DROP.equals(input[0])) {
				player->drop(input);
			}
			else if (Commands::THROW.equals(input[0])) {
				player->throwObject(input);
			}
			else {
				cout << "I could not understand the last command." << endl;
			}
			break;
		case 3:
			break;
		case 4:
			if (Commands::TAKE.equals(input[0]) || Commands::PICK.equals(input[0])) {
				player->take(input);
			}
			else if (Commands::UNLOCK.equals(input[0])) {
				player->unlock(input);
			}
			else if (Commands::PUT.equals(input[0])) {
				player->put(input);
			}
			else {
				cout << "I could not understand the last command." << endl;
			}
			break;
		default:
			
			cout << "I could not understand the last command." << endl;
			
			break;
	}
	return OK;
}

bool World::isEndCommand(const vector<string> &input)
{
	bool result = false;
	if (input.size() == 1 && Commands::QUIT.equals(input[0])) {
		result = true;
	}
	return result;
}
