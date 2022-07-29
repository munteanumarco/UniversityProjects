#include "Participant.h"
#include "utils.h"

Participant::Participant(string name, int score)
	: name(name), score(score)
{
}

Participant::~Participant()
{
}

string Participant::getName()
{
	return this->name;
}

int Participant::getScore()
{
	return this->score;
}

void Participant::setScore(int newScore)
{
	this->score = newScore;
}

ostream& operator<<(ostream& out, const Participant& p)
{
	out << p.name << ";" << p.score << "\n";
	return out;
}

istream& operator>>(istream& in, Participant& p)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 2)
	{
		return in;
	}

	p.name = tokens[0];
	p.score = stoi(tokens[1]);

	return in;
}
