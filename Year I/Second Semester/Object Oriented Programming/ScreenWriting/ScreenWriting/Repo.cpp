#include "Repo.h"
#include <fstream>

void Repo::loadData()
{
	ifstream ideasFile;
	ideasFile.open("ideas.txt");
	if (ideasFile.is_open())
	{
		Idea i;
		while (ideasFile >> i)
		{
			this->ideas.push_back(i);
		}
		ideasFile.close();
	}
	ifstream writersFile;
	writersFile.open("writers.txt");
	if (writersFile.is_open())
	{
		Writer w;
		while (writersFile >> w)
		{
			this->writers.push_back(w);
		}
		writersFile.close();
	}

}

void Repo::saveIdeas()
{
	ofstream ideasFile;
	ideasFile.open("ideas.txt");
	if (ideasFile.is_open())
	{
		for (Idea i : this->ideas)
		{
			ideasFile << i;
		}
		ideasFile.close();
	}
}

void Repo::saveWriters()
{
	ofstream writersFile;
	writersFile.open("writers.txt");
	if (writersFile.is_open())
	{
		for (Writer w : this->writers)
		{
			writersFile << w;
		}
		writersFile.close();
	}
}

Repo::Repo()
{
	this->loadData();
}

vector<Writer>& Repo::getWriters()
{
	return this->writers;
}

vector<Idea> Repo::getIdeas()
{
	return this->ideas;
}

void Repo::addIdea(Idea i)
{
	this->ideas.push_back(i);
}

bool Repo::checkUniqueDescription(Idea i)
{
	for (Idea idea : this->ideas)
	{
		if (i.getDescription() == idea.getDescription())
		{
			return false;
		}
	}
	return true;
}

void Repo::acceptIdea(int index)
{
	this->ideas[index].setStatus("accepted");
}
