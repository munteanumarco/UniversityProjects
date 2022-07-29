#pragma once
#include <string>
#include <iostream>
using namespace std;

class Idea {
private:
	string description;
	string status;
	string creator;
	int act;
public:
	Idea(string description = "", string status = "", string creator = "", int act = 0);
	string getDescription();
	string getStatus();
	string getCreator();
	int getAct();
	void setStatus(string newStatus);
	string toString();
	friend ostream& operator<<(ostream& out, Idea& i);
	friend istream& operator>>(istream& in, Idea& i);
};