#include "utils.h"
#include <sstream>
vector<string> tokenize(string str, char delimiter)
{
	vector<string> res{};
	stringstream s{ str };
	string token;
	while (getline(s, token, delimiter))
	{
		res.push_back(token);
	}
	return res;
}