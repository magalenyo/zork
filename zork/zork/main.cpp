// Author: Miguel Ángel Bueno Rivera (magalenyo7@gmail.com)

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include <World.h>
#include <Commands.h>
#include <StringUtils.h>

int main()
{
	cout << "Welcome to ZORK." << endl;
	World world;
	string input;
	vector<string> arguments;
	bool end = false;

	while (!end) {
		getline(cin, input);
		string lowCaseInput = StringUtils::toLowerCase(input);
		arguments = StringUtils::tokenize(lowCaseInput);

		cout << endl;
		ResultEnum result = world.parseCommand(arguments);
		
		if (result == QUIT) {
			cout << "Bye!" << endl;
			end = true;
		}
		else if (result == FINISHED) {
			world.finishGame();
			end = true;
		}
		else if (result == UNKNOWN) {
			cout << "Please, enter a valid command." << endl;
		}
		
	}
	
	return 0;
}