#include "Report.h"
#include "Utils.h"
#include <sstream>

Report::Report(string description, string reporter, float latitude, float longitude, int validated, int votes)
	: description(description), reporter(reporter), latitude(latitude), longitude(longitude), validated(validated), votes(votes)
{
}

string Report::getDescription()
{
	return this->description;
}

string Report::getReporter()
{
	return this->reporter;
}

float Report::getLatitude()
{
	return this->latitude;
}

float Report::getLongitude()
{
	return this->longitude;
}

int Report::checkValidated()
{
	return this->validated;
}

int Report::getValidated()
{
	return this->validated;
}

void Report::setDescription(string newDesc)
{
	this->description = newDesc;
}

void Report::setReporter(string newReporter)
{
	this->reporter = newReporter;
}

void Report::setLatitude(float newLat)
{
	this->latitude = newLat;
}

void Report::setLongitude(float newLong)
{
	this->longitude = newLong;
}

void Report::setValidate(int newValidated)
{
	this->validated = newValidated;
}

string Report::toString()
{
	stringstream out;
	out << this->description << ";" << this->reporter << ";" << this->latitude << ";" << this->longitude << ";" << this->validated << ";" << this->votes << "\n";
	return out.str();
}

int Report::getVotes()
{
	return this->votes;
}

void Report::setVotes(int newVotes)
{
	this->votes = newVotes;
}

bool Report::operator==(Report r)
{
	return (this->latitude == r.latitude) && (this->longitude == r.longitude) && (this->reporter == r.reporter);
}

ostream& operator<<(ostream& out, Report& r)
{
	out << r.toString();
	return out;
}

istream& operator>>(istream& in, Report& r)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 6)
	{
		return in;
	}
	r.description = tokens[0];
	r.reporter = tokens[1];
	r.latitude = stof(tokens[2]);
	r.longitude = stof(tokens[3]);
	r.validated = stoi(tokens[4]);
	r.votes = stoi(tokens[5]);

	return in;
}
