#include "StringUtils.h"

string StringUtils::toLowerCase(const string &param)
{
	string newString = param;
	transform(newString.begin(), newString.end(), newString.begin(), ::tolower);
	return newString;
}

vector<string> StringUtils::tokenize(const string & param) {
	vector<string> result;

	istringstream iss(param);
	string str;
	while (iss >> str) {
		result.push_back(str);
	}

	return result;
}
