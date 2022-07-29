#include "repo_tasks.h"
#include <fstream>
#include <algorithm>

void RepoTasks::loadData()
{
	ifstream file;
	file.open("tasks.txt");
	if (file.is_open())
	{
		Task t;
		while (file >> t)
		{
			this->tasks.push_back(t);
		}
		file.close();
	}
}

void RepoTasks::saveData()
{
	ofstream file;
	file.open("tasks.txt");
	if (file.is_open())
	{
		for (Task t : this->tasks)
		{
			file << t;
		}
		file.close();
	}
}

void RepoTasks::sortTasks()
{
	sort(this->tasks.begin(), this->tasks.end(), [](Task t1, Task t2) {
		return t1.getStatus() > t2.getStatus();
		});
}

RepoTasks::RepoTasks()
{
	this->loadData();
	this->sortTasks();
}

RepoTasks::~RepoTasks()
{
}

vector<Task> RepoTasks::getTasks()
{
	return this->tasks;
}

void RepoTasks::addTask(Task t)
{
	this->tasks.push_back(t);
	this->sortTasks();
	this->notify();
	this->saveData();
}

void RepoTasks::removeTask(Task t)
{
	for (int i = 0; i < this->tasks.size(); i++)
	{
		if (this->tasks[i] == t)
		{
			this->tasks.erase(tasks.begin() + i);
			break;
		}
	}
	this->sortTasks();
	this->notify();
	this->saveData();
}

void RepoTasks::updateTaskStatus(Task t, string newStatus, int newId)
{
	for (int i = 0; i < this->tasks.size(); i++)
	{
		if (this->tasks[i] == t)
		{
			this->tasks[i].setStatus(newStatus);
			this->tasks[i].setId(newId);
			break;
		}
	}
	this->sortTasks();
	this->notify();
	this->saveData();
}
