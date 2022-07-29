#include "repo_questions.h"
#include <fstream>
#include <algorithm>

RepoQuestions::RepoQuestions()
{
	this->loadData();
}


void RepoQuestions::loadData()
{
	ifstream file;
	file.open("questions.txt");
	if (file.is_open())
	{
		Question q;
		while (file >> q)
		{
			this->questions.push_back(q);
		}
	}
	file.close();
	sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2) {
		return q1.getId() < q2.getId();
		});
}

void RepoQuestions::saveData()
{
	ofstream file;
	file.open("questions.txt");
	for (auto q : this->questions)
	{
		file << q;
	}
	file.close();
}

RepoQuestions::~RepoQuestions()
{
}

void RepoQuestions::addQuestion(Question q)
{
	int pos = this->checkExistence(q);
	if (pos == -1)
	{
		this->questions.push_back(q);
		sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2) {
			return q1.getId() < q2.getId();
			});
		this->saveData();
		//this->notify();
	}
	else
	{
		throw exception();
	}
}

int RepoQuestions::checkExistence(Question q)
{
	for (int i = 0; i < this->questions.size(); i++)
	{
		if (this->questions[i].getId() == q.getId())
		{
			return i;
		}
	}
	return -1;
}

vector<Question>& RepoQuestions::getQuestions()
{
	return this->questions;
}
