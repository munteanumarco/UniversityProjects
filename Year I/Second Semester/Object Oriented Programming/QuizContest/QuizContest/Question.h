#pragma once
#include <string>
#include <iostream>
using namespace std;

class Question {
private:
	int id;
	string text;
	string correct_answer;
	int score;
public:
	Question(int id = 0, string text = "", string correct_answer = "", int score = 0);
	~Question();
	int getId();
	int getScore();
	string getText();
	string getCorrectAnswer();
	string toString();
	friend istream& operator>>(istream& in, Question& q);
	friend ostream& operator<<(ostream& out, const Question& q);
};