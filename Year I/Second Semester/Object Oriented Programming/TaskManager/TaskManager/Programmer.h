#pragma once
#include <string>
#include <iostream>
using namespace std;
class Programmer {
private:
	string name;
	int id;
public:
	Programmer(string name = "", int id = 0);
	~Programmer();
	string getName();
	int getId();
	friend ostream& operator<<(ostream& out, const Programmer& p);
	friend istream& operator>>(istream& in, Programmer& p);

};