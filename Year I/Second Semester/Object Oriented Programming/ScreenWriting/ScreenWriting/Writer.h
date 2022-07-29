#pragma once
#include <string>
#include <iostream>
using namespace std;

class Writer {
private:
	string name;
	string expertise;
public:
	Writer(string name = "", string expertise = "");
	string getName();
	string getExpertise();
	void setExpertise(string newExpertise);
	string toString();
	friend ostream& operator<<(ostream& out, Writer& w);
	friend istream& operator>>(istream& in, Writer& w);

};