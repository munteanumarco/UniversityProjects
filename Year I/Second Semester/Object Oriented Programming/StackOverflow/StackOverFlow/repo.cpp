#include "repo.h"
#include <iostream>
#include <algorithm>

void Repository::loadData()
{
	ifstream usersFile;
	usersFile.open("users.txt");
	if (usersFile.is_open())
	{
		User u;
		while (usersFile >> u)
		{
			this->users.push_back(u);
		}
		usersFile.close();
	}
	ifstream questionsFile;
	questionsFile.open("questions.txt");
	if (questionsFile.is_open())
	{	
		Question q;
		while (questionsFile >> q)
		{
			this->questions.push_back(q);
		}
		questionsFile.close();
	}
	ifstream answersFile;
	answersFile.open("answers.txt");
	if (answersFile.is_open())
	{
		Answer a;
		while (answersFile >> a)
		{
			this->answers.push_back(a);
		}
		answersFile.close();
	}
}

void Repository::saveAnswers()
{
	ofstream answersFile;
	answersFile.open("answers.txt");
	if (answersFile.is_open())
	{
		for (Answer a : this->answers)
		{
			answersFile << a;
		}
		answersFile.close();
	}
}

void Repository::saveQuestions()
{
	ofstream questionsFile;
	questionsFile.open("questions.txt");
	if (questionsFile.is_open())
	{
		for (Question q : this->questions)
		{
			questionsFile << q;
		}
		questionsFile.close();
	}
}

void Repository::sortQuestions()
{
	sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2) {
		return q1.getAnswers() > q2.getAnswers();
		});
}

int Repository::checkMatchingLetters(string s1, string s2)
{
	//Always have samlles string in s1
	if (s1.size() > s2.size())
	{
		swap(s1, s2);
	}
	int count = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == s2[i])
		{
			count += 1;
		}
	}
	return count;

}

void Repository::addQuestion(Question q)
{
	this->questions.push_back(q);
	this->sortQuestions();
	this->notify();
	this->saveQuestions();
}

vector<Question> Repository::getQuestions()
{
	return this->questions;
}

vector<User> Repository::getUsers()
{
	return this->users;
}

vector<Answer> Repository::getAnswersForQuestion(Question q)
{
	vector<Answer> result;
	for (Answer a : this->answers)
	{
		if (a.getQuestionId() == q.getId())
		{
			result.push_back(a);
		}
	}
	return result;
}

void Repository::addAnswer(Answer a)
{
	this->answers.push_back(a);
	this->saveAnswers();
}

void Repository::updateVotes(Answer a, int newVotes)
{
	for (int i = 0; i < this->answers.size(); i++)
	{
		if (this->answers[i] == a)
		{
			this->answers[i].setVotes(newVotes);
			break;
		}
	}
	this->notify();
	this->saveAnswers();
}

Question Repository::getMatchingQuestion(string text)
{
	Question result;
	int matchingLetters = 0;
	for (Question q : this->questions)
	{
		int currentMatchingLetters = this->checkMatchingLetters(q.getText(), text);
		if (currentMatchingLetters > matchingLetters)
		{
			matchingLetters = currentMatchingLetters;
			result = q;
		}
	}
	return result;

}


Repository::Repository()
{
	this->loadData();
	this->sortQuestions();
}