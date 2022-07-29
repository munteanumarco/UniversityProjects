#include "repo_programmers.h"
#include <fstream>

void RepoProgrammers::loadData()
{
	ifstream file;
	file.open("programmers.txt");
	if (file.is_open())
	{
		Programmer p;
		while (file >> p)
		{
			this->programmers.push_back(p);
		}
		file.close();
	}
}

RepoProgrammers::RepoProgrammers()
{
	this->loadData();
}

RepoProgrammers::~RepoProgrammers()
{
}

vector<Programmer> RepoProgrammers::getProgrammers()
{
	return this->programmers;
}

Programmer RepoProgrammers::getProgrammerById(int id)
{
	for (Programmer p : this->programmers)
	{
		if (p.getId() == id)
		{
			return p;
		}
	}
}
