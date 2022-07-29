#pragma once
#include "Programmer.h"
#include <vector>

class RepoProgrammers {
private:
	vector<Programmer> programmers;
	void loadData();
public:
	RepoProgrammers();
	~RepoProgrammers();
	vector<Programmer> getProgrammers();
	Programmer getProgrammerById(int id);
};