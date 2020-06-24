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
	static string toLowerCase(const string &param);
	static vector<string> tokenize(const string &param);
};

#endif