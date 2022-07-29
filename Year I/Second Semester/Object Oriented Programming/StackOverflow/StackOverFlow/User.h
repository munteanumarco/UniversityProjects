#pragma once
#include <string>
#include <fstream>
using namespace std;

class User {
private:
	string name;
public:
	User(string name = "");
	~User();
	void setName(string newName);
	string getName();
	friend istream& operator>>(istream& in, User& u);

};