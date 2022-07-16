#pragma once
#include "SortedBag.h"
#include <stack>
class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);
	int currentNode;
	int currentNodeFreq;
	int* stack;
	int current_size;
	int capacity;
	void push(int data);
	int pop();
	int top();
    void resize();
    void empty();
public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

