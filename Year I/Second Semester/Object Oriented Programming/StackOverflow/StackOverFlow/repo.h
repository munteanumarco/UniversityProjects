#pragma once
#include "Answer.h"
#include "Question.h"
#include "User.h"
#include "Observer.h"

class Repository : public Subject {
private:
	vector<User> users;
	vector<Question> questions;
	vector<Answer> answers;
	void loadData();
	void saveAnswers();
	void saveQuestions();
	void sortQuestions();
	int checkMatchingLetters(string s1, string s2);
public:
	Repository();
	void addQuestion(Question q);
	vector<Question> getQuestions();
	vector<User> getUsers();
	vector<Answer> getAnswersForQuestion(Question q);
	void addAnswer(Answer a);
	void updateVotes(Answer a, int newVotes);
	Question getMatchingQuestion(string text);
};