#pragma once
#include "Repo.h"

class Controller {
private:
	Repo& repo;
public:
	Controller(Repo& repo);
	vector<Idea> getIdeas();
	vector<Writer>& getWriters();
	void addIdea(Idea i);
	bool checkUniqueDescription(Idea i);
	void acceptIdea(int index);
};