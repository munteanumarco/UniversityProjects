#pragma once
#include <string>
using namespace std;
class Task {
private:
	string description;
	string status;
	int id;
public:
	Task(string description = "", string status = "", int id = 0);
	~Task();
	string getDescription();
	string getStatus();
	int getId();
	string toString();
	void setStatus(string newStatus);
	void setId(int newId);
	friend ostream& operator<<(ostream& out, Task& t);
	friend istream& operator>>(istream& in, Task& t);
	bool operator==(Task t);
};