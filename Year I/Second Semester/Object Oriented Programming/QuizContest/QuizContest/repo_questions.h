#pragma once
#include <vector>
#include "Question.h"
#include "observer.h"

class RepoQuestions : public Observable {
private:
	vector<Question> questions;
	void loadData();
	void saveData();
public:
	RepoQuestions();
	~RepoQuestions();
	void addQuestion(Question q);
	int checkExistence(Question q);
	vector<Question>& getQuestions();
};