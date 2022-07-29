#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Observable {
private:
	vector <Observer*> observers;
public:
	virtual ~Observable() {}
	
	void addObserver(Observer* obs)
	{
		this->observers.push_back(obs);
	}

	void removeObserver(Observer* obs)
	{
		auto it = find(this->observers.begin(), this->observers.end(), obs);
		if (it != this->observers.end())
		{
			this->observers.erase(it);
		}
	}

	void notify()
	{
		for (auto obs : observers)
		{
			obs->update();
		}
	}
};