#include "World.h"

World::World()
{
	// Rooms
	Room* crossroad = new Room("Crossroad","You're at a crossroad and you can take two different paths, to the west or the east. You can hear growls coming from the east path.");
	Room* westPath = new Room("West path", "You see what appears to be an empty house on the west and a road to the north.");
	Room* road = new Room("Road", "The road is a dead end, but you see a treehouse you can climb.");
	Room* treehouse = new Room("Treehouse", "You've climbed up to the treehouse. In the distance, you can see the temple.");
	Room* entrance = new Room("House entrance", "You're at the entrance and you knock, but there's no answer. The door is locked.");
	Room* house = new Room("House", "You finally got into the house");
	Room* eastPath = new Room("East path", "Two wolves are blocking the path. You see an alternative path heading east: a damaged bridge over a furious river.");
	Room* wolves = new Room("Wolves!", "You're in front of two fierce wolves, what are you going to do?");
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

	//Items
	Item* goldenIdol = new Item("Golden Idol", "This is the sacred idol, small but heavy.", NULL, OBJECTIVE);
	Item* key = new Item("Rusty key", "This is the key to the house, looks old and rusty.", NULL, UTIL);
	Item* berries = new Item("Berries", "Juicy berries.", NULL, CONSUMABLE);
	Item* sword = new Item("Sword", "A nice sharp sword", NULL, WEAPON);
	Item* rock = new Item("Rock", "Just a regular rock. This can make some noise.", NULL, UTIL);
	Item* backpack = new Item("Backpack", "With it, you can carry more objects.", NULL, UTIL);

	entities.push_back(goldenIdol);
	entities.push_back(key);
	entities.push_back(berries);
	entities.push_back(sword);
	entities.push_back(rock);
	entities.push_back(backpack);

	//treehouse->

	// Characters
	Character* wolf1 = new Character("A big wolf", "This wolf has razor sharp teeth.", wolves);
	Character* wolf2 = new Character("A smaller wolf", "Not so threatening, but still dangerous.", wolves);
	
	player = new Player("Player", "You're a braverous explorer. Your mission is to find your way to the temple to deliver the idol.", crossroad);
	
	entities.push_back(wolf1);
	entities.push_back(wolf2);
	entities.push_back(player);
	

	
}

void World::parseCommand(const vector<string> &input)
{
	switch (input.size()) {
		case 0:
			if (Commands::NORTH.equals(input[0])) {
				//player.go(input);
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
	}
}

bool World::isEndCommand(const vector<string> &input)
{
	bool result = false;
	if (input.size() == 1 && Commands::QUIT.equals(input[0])) {
		result = true;
	}
	return result;
}
