#include "utils.h"
#include <sstream>

vector<string> tokenize(string line, char delimiter)
{
	vector<string> result;
	stringstream s{ line };
	string token;
	while (getline(s, token, delimiter))
	{
		result.push_back(token);
	}
	return result;
}