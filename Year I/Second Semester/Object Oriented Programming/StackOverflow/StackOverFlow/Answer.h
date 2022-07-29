#pragma once
#include <string>
#include "utils.h"
#include <iostream>

class Answer {
private:
	int answerId;
	int questionId;
	string name;
	string text;
	int votes;
public:
	Answer(int answerId = 0, int questionId = 0, string name = "", string text = "", int votes = 0);
	~Answer();
	int getAnswerId();
	int getQuestionId();
	int getVotes();
	void setVotes(int newVotes);
	string getName();
	string getText();
	string toString();
	friend ostream& operator<<(ostream& out, Answer& a);
	friend istream& operator>>(istream& in, Answer& a);
	bool operator==(Answer a);

};