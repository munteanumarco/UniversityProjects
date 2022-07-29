#include "Answer.h"
#include <sstream>
#include "utils.h"
Answer::Answer(int answerId, int questionId, string name, string text, int votes)
	: answerId(answerId), questionId(questionId), name(name), text(text), votes(votes)
{
}

Answer::~Answer()
{
}

int Answer::getAnswerId()
{
	return this->answerId;
}

int Answer::getQuestionId()
{
	return this->questionId;
}

int Answer::getVotes()
{
	return this->votes;
}

void Answer::setVotes(int newVotes)
{
	this->votes = newVotes;
}

string Answer::getName()
{
	return this->name;
}

string Answer::getText()
{
	return this->text;
}

string Answer::toString()
{
	stringstream out;
	out << this->answerId << ";" << this->questionId << ";" << this->name << ";" << this->text << ";" << this->votes << "\n";
	return out.str();
}

bool Answer::operator==(Answer a)
{
	return this->answerId == a.answerId && this->questionId == a.questionId;
}

ostream& operator<<(ostream& out, Answer& a)
{
	out << a.toString();
	return out;
}

istream& operator>>(istream& in, Answer& a)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 5)
	{
		return in;
	}
	a.answerId = stoi(tokens[0]);
	a.questionId = stoi(tokens[1]);
	a.name = tokens[2];
	a.text = tokens[3];
	a.votes = stoi(tokens[4]);
	return in;
}
