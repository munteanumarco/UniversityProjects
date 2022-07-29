#include "Question.h"
#include <sstream>
Question::Question(int id, string text, string name, int answers)
	: id(id), text(text), name(name), answers(answers)
{
}

Question::~Question()
{
}

int Question::getId()
{
	return this->id;
}

string Question::getText()
{
	return this->text;
}

string Question::getName()
{
	return this->name;
}

int Question::getAnswers()
{
	return this->answers;
}

void Question::setAnswers(int newAnswers)
{
	this->answers = newAnswers;
}

void Question::setId(int newId)
{
	this->id = newId;
}

void Question::setName(string newName)
{
	this->name = newName;
}

void Question::setText(string newText)
{
	this->text = newText;
}

string Question::toString()
{
	stringstream out;
	out << this->id << ";" << this->text << ";" << this->name << "\n";
	return out.str();
}

ostream& operator<<(ostream& out, Question& q)
{
	out << q.toString();
	return out;
}

istream& operator>>(istream& in, Question& q)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 3)
	{
		return in;
	}
	q.id = stoi(tokens[0]);
	q.text = tokens[1];
	q.name = tokens[2];

	return in;
}
