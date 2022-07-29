#include "Writer.h"
#include <sstream>
#include "Utils.h"

Writer::Writer(string name, string expertise)
	: name(name), expertise(expertise)
{
}

string Writer::getName()
{
	return this->name;
}

string Writer::getExpertise()
{
	return this->expertise;
}

void Writer::setExpertise(string newExpertise)
{
	this->expertise = newExpertise;
}

string Writer::toString()
{
	stringstream out;
	out << this->name << ";" << this->expertise << "\n";
	return out.str();
}

ostream& operator<<(ostream& out, Writer& w)
{
	out << w.toString();
	return out;
}

istream& operator>>(istream& in, Writer& w)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 2)
	{
		return in;
	}
	w.name = tokens[0];
	w.expertise = tokens[1];
	return in;
}
