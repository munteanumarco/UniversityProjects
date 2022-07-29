#pragma once
#include "Writer.h"
#include "Idea.h"
#include <vector>

class Repo {
private:
	vector<Idea> ideas;
	vector<Writer> writers;
	void loadData();
	void saveIdeas();
	void saveWriters();
public:
	Repo();
	vector<Writer>& getWriters();
	vector<Idea> getIdeas();
	void addIdea(Idea i);
	bool checkUniqueDescription(Idea i);
	void acceptIdea(int index);
};