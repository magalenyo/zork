// Author: Miguel Ángel Bueno Rivera (magalenyo7@gmail.com)

using namespace std;

#include <iostream>
#include <string>
#include <Commands.h>

int main()
{
	cout << "Welcome to ZORK." << endl;
	string input;
	//getline(cin, input);
	while (cin >> input) {
		cout << input << endl;
	}
	
	cout << Commands::NORTH.default << " " << Commands::NORTH.shortcut << endl;

	return 0;
	//while(input.)
}