// Author: Miguel Ángel Bueno Rivera (magalenyo7@gmail.com)

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <World.h>
#include <Commands.h>

// pre: param is a string separated by spaces
// post: returns a vector of string; this vector is the param tokenized
vector<string> tokenize(string param) {
	vector<string> result;

	istringstream iss( param );
	string str;
	while (iss >> str) {
		result.push_back(str);
	}

	return result;
}

int main()
{
	cout << "Welcome to ZORK." << endl;
	World world;
	string input;
	vector<string> arguments = tokenize(input);
	bool end = false;

	while (!end) {
		getline(cin, input);
		arguments = tokenize(input);
		cout << endl;
		ResultEnum result = world.parseCommand(tokenize(input));
		if (result == QUIT) {
			end = true;
		}
		else if (result == UNKNOWN) {
			cout << "Please, enter a valid command" << endl;
		}
		
	}
	cout << "Bye." << endl;
	
	return 0;
}