#include "cont.h"

Controller::Controller(Repository &repo)
	: repo(repo)
{
}

void Controller::addObserver(Observer* o)
{
	this->repo.addObserver(o);
}

void Controller::addQuestion(Question q)
{
	this->repo.addQuestion(q);
}

vector<Question> Controller::getQuestions()
{
	return this->repo.getQuestions();
}

vector<Answer> Controller::getAnswersForQuestion(Question q)
{
	return this->repo.getAnswersForQuestion(q);
}

void Controller::addAnswer(Answer a)
{
	this->repo.addAnswer(a);
}

void Controller::updateVotes(Answer a, int newVotes)
{
	this->repo.updateVotes(a, newVotes);
}

Question Controller::getMatchingQuestion(string text)
{
	return this->repo.getMatchingQuestion(text);
}
