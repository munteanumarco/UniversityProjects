#pragma once
#include <string>
#include <iostream>

using namespace std;

class Participant {
private:
	string name;
	int score;
public:
	Participant(string name = "", int score = 0);
	~Participant();
	string getName();
	int getScore();
	void setScore(int newScore);
	friend ostream& operator<<(ostream& out, const Participant& p);
	friend istream& operator>>(istream& in, Participant& p);
};