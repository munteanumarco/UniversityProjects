#include "repo_participants.h"
#include <fstream>

void RepoParticipants::loadData()
{
	ifstream file;
	file.open("participants.txt");
	if (file.is_open())
	{
		Participant p;
		while (file >> p)
		{
			this->participants.push_back(p);
		}
	}
	file.close();
}

RepoParticipants::RepoParticipants()
{
	this->loadData();
}

RepoParticipants::~RepoParticipants()
{
}

vector<Participant>& RepoParticipants::getParticipants()
{
	return this->participants;
}

void RepoParticipants::updateParticipantScore(Question q, string answer, Participant& p)
{
	if (q.getCorrectAnswer() == answer)
	{
		int newScore = p.getScore() + q.getScore();
		p.setScore(newScore);
	}
	else
	{
		throw exception();
	}
}
