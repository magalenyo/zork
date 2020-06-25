/**
* StringUtils.h
*
*
* Author: Miguel Ángel Bueno Rivera
*
*/

#ifndef StringUtils_h
#define StringUtils_h

#include <string>
#include <algorithm>    // std::transform
#include <vector>
#include <sstream> 


using namespace std;

class StringUtils
{
public:

	// pre: --
	// post: returns the string in lower case
	static string toLowerCase(const string &param);

	// --
	// post: returns a vector of string; this vector is the param tokenized
	static vector<string> tokenize(const string &param);
};

#endif