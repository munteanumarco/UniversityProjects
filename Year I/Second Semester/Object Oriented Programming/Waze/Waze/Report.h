#pragma once
#include <string>
#include <iostream>
using namespace std;

class Report {
private:
	string description;
	string reporter;
	float latitude, longitude;
	int validated;
	int votes;
public:
	Report(string description = "", string reporter = "", float latitude = 0, float longitude = 0, int validated = 0, int votes = 0);
	string getDescription();
	string getReporter();
	float getLatitude();
	float getLongitude();
	int checkValidated();
	int getValidated();
	void setDescription(string newDesc);
	void setReporter(string newReporter);
	void setLatitude(float newLat);
	void setLongitude(float newLong);
	void setValidate(int newValidated);
	string toString();
	int getVotes();
	void setVotes(int newVotes);
	friend ostream& operator<<(ostream& out, Report& r);
	friend istream& operator>>(istream& in, Report& r);
	bool operator==(Report r);
};