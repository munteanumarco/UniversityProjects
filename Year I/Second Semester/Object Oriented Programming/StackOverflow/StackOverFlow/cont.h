#pragma once
#include "repo.h"

class Controller {
private:
	Repository &repo;
public:
	Controller(Repository &repo);
	void addObserver(Observer* o);
	void addQuestion(Question q);
	vector<Question> getQuestions();
	vector<Answer> getAnswersForQuestion(Question q);
	void addAnswer(Answer a);
	void updateVotes(Answer a, int newVotes);
	Question getMatchingQuestion(string text);
};