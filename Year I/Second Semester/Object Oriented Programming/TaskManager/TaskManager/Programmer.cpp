#include "Programmer.h"
#include "utils.h"

Programmer::Programmer(string name, int id)
	: name(name), id(id)
{
}

Programmer::~Programmer()
{
}

string Programmer::getName()
{
	return this->name;
}

int Programmer::getId()
{
	return this->id;
}

ostream& operator<<(ostream& out, const Programmer& p)
{
	out << p.name << ";" << p.id << "\n";
	return out;
}

istream& operator>>(istream& in, Programmer& p)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 2)
	{
		return in;
	}

	p.name = tokens[0];
	p.id = stoi(tokens[1]);

	return in;
}
