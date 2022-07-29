#include "Question.h"
#include "utils.h"
Question::Question(int id, string text, string correct_answer, int score)
	: id(id), text(text), correct_answer(correct_answer), score(score)
{
}

Question::~Question()
{
}

int Question::getId()
{
	return this->id;
}

string Question::getCorrectAnswer()
{
	return this->correct_answer;
}

string Question::toString()
{
	stringstream out;
	out << this->id << ";" << this->text << ";" << this->correct_answer << ";" << this->score << "\n";
	return out.str();
}

int Question::getScore()
{
	return this->score;
}

string Question::getText()
{
	return this->text;
}

istream& operator>>(istream& in, Question& q)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 4)
	{
		return in;
	}

	q.id = stoi(tokens[0]);
	q.text = tokens[1];
	q.correct_answer = tokens[2];
	q.score = stoi(tokens[3]);

	return in;
}

ostream& operator<<(ostream& out, const Question& q)
{
	out << q.id << ";" << q.text << ";" << q.correct_answer << ";" << q.score << "\n";
	return out;
}
