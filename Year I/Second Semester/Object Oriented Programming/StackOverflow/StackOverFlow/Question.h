#pragma once
#include <string>
#include "utils.h"
#include <iostream>
class Question {
private:
	int id;
	string text;
	string name;
	int answers;
public:
	Question(int id = 0, string text = "", string name = "", int answers = 0);
	~Question();
	int getId();
	string getText();
	string getName();
	int getAnswers();
	void setAnswers(int newAnswers);
	void setId(int newId);
	void setName(string newName);
	void setText(string newText);
	string toString();
	friend ostream& operator<<(ostream& out, Question& q);
	friend istream& operator>>(istream& in, Question& q);
};