#include "User.h"
#include "utils.h"
User::User(string name)
	: name(name)
{
}

User::~User()
{
}

void User::setName(string newName)
{
	this->name = newName;
}

string User::getName()
{
	return this->name;
}

istream& operator>>(istream& in, User& u)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 1)
	{
		return in;
	}
	u.name = tokens[0];
	return in;
}
