#include "StringUtils.h"

string StringUtils::toLowerCase(const string &param)
{
	string newString = param;
	transform(newString.begin(), newString.end(), newString.begin(), ::tolower);
	return newString;
}

// pre: param is a string separated by spaces
// post: returns a vector of string; this vector is the param tokenized
vector<string> StringUtils::tokenize(const string & param) {
	vector<string> result;

	istringstream iss(param);
	string str;
	while (iss >> str) {
		result.push_back(str);
	}

	return result;
}
