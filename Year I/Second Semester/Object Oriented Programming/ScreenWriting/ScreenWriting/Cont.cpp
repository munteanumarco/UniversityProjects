#include "Cont.h"

Controller::Controller(Repo& repo)
	: repo(repo)
{
}

vector<Idea> Controller::getIdeas()
{
	return this->repo.getIdeas();
}

vector<Writer>& Controller::getWriters()
{
	return this->repo.getWriters();
}

void Controller::addIdea(Idea i)
{
	this->repo.addIdea(i);
}

bool Controller::checkUniqueDescription(Idea i)
{
	return this->repo.checkUniqueDescription(i);
}

void Controller::acceptIdea(int index)
{
	this->repo.acceptIdea(index);
}
