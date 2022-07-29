#include "utils.h"

vector<string> tokenize(string s, char delimiter)
{
	vector<string> result;
	stringstream ss(s);
	string token;
	while (getline(ss, token, delimiter))
	{
		result.push_back(token);
	}
	return result;
}