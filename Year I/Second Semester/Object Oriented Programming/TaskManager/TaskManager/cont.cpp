#include "cont.h"


Controller::Controller(RepoTasks &repoT, RepoProgrammers &repoP)
	: repoT(repoT), repoP(repoP)
{
}

vector<Task> Controller::getTasks()
{
	return this->repoT.getTasks();
}

vector<Programmer> Controller::getProgrammers()
{
	return this->repoP.getProgrammers();
}

void Controller::addObserver(Observer* o)
{
	this->repoT.addObserver(o);
}

void Controller::removeTask(Task t)
{
	this->repoT.removeTask(t);
}

void Controller::addTask(Task t)
{
	this->repoT.addTask(t);
}

void Controller::updateTaskStatus(Task t, string newStatus, int newId)
{
	this->repoT.updateTaskStatus(t, newStatus, newId);
}

Programmer Controller::getProgrammerById(int id)
{
	return this->repoP.getProgrammerById(id);
}
