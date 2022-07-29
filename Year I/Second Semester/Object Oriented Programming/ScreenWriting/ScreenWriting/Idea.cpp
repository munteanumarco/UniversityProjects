#include "Idea.h"
#include "Utils.h"

Idea::Idea(string description, string status, string creator, int act)
	: description(description), status(status), creator(creator), act(act)
{

}

string Idea::getDescription()
{
	return this->description;
}

string Idea::getStatus()
{
	return this->status;
}

string Idea::getCreator()
{
	return this->creator;
}

int Idea::getAct()
{
	return this->act;
}

void Idea::setStatus(string newStatus)
{
	this->status = newStatus;
}

string Idea::toString()
{
	stringstream out;
	out << this->description << ";" << this->status << ";" << this->creator << ";" << this->act << "\n";
	return out.str();
}

ostream& operator<<(ostream& out, Idea& i)
{
	out << i.toString();
	return out;
}

istream& operator>>(istream& in, Idea& i)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 4)
	{
		return in;
	}
	i.description = tokens[0];
	i.status = tokens[1];
	i.creator = tokens[2];
	i.act = stoi(tokens[3]);
	
	return in;
}
