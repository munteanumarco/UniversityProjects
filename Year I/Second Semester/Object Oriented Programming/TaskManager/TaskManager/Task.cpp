#include "Task.h"
#include "utils.h"
#include <sstream>

Task::Task(string description, string status, int id)
	: description(description), status(status), id(id)
{
}

Task::~Task()
{
}

string Task::getDescription()
{
	return this->description;
}

string Task::getStatus()
{
	return this->status;
}

int Task::getId()
{
	return this->id;
}

string Task::toString()
{	
	stringstream out;
	out << this->description << ";" << this->status << ";" << this->id << "\n";
	return out.str();
}

void Task::setStatus(string newStatus)
{
	this->status = newStatus;
}

void Task::setId(int newId)
{
	this->id = newId;
}

bool Task::operator==(Task t)
{
	return (this->description == t.description) && (this->id == t.id) && (this->status == t.status);
}

ostream& operator<<(ostream& out, Task& t)
{
	out << t.toString();
	return out;
}

istream& operator>>(istream& in, Task& t)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 3)
	{
		return in;
	}

	t.description = tokens[0];
	t.status = tokens[1];
	t.id = stoi(tokens[2]);
	
	return in;
}
