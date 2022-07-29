#pragma once
#include "Task.h"
#include <vector>
#include "Observer.h"

class RepoTasks : public Subject {
private:
	vector<Task> tasks;
	void loadData();
	void saveData();
	void sortTasks();
public:
	RepoTasks();
	~RepoTasks();
	vector<Task> getTasks();
	void addTask(Task t);
	void removeTask(Task t);
	void updateTaskStatus(Task t, string newStatus, int newId);
};