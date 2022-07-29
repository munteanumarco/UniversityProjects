#pragma once
#include "repo_tasks.h"
#include "repo_programmers.h"

class Controller {
private:
	RepoTasks &repoT;
	RepoProgrammers &repoP;
public:
	Controller(RepoTasks &repoT, RepoProgrammers &repoP);
	vector<Task> getTasks();
	vector<Programmer> getProgrammers();
	void addObserver(Observer* o);
	void removeTask(Task t);
	void addTask(Task t);
	void updateTaskStatus(Task t, string newStatus, int newId);
	Programmer getProgrammerById(int id);
};