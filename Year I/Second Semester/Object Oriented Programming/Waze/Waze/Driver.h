#pragma once
#include <string>
#include <iostream>
using namespace std;


class Driver {
private:
	string name;
	string status;
	float latitude, longitude;
	int score;
public:
	Driver(string name = "", string status = "", float latitude = 0, float longitude = 0, int score = 0);
	string getName();
	string getStatus();
	float getLatitude();
	float getLongitude();
	int getScore();
	void setStatus(string newStatus);
	void setScore(int newScore);
	string toString();
	void setLatitude(int newLat);
	void setLongitude(int newLong);
	friend ostream& operator<<(ostream& out, Driver& d);
	friend istream& operator>>(istream& in, Driver& d);
	bool operator==(Driver d);

};