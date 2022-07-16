#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	this->current = 0;
}

void ListIterator::first(){
	this->current = 0;
}

void ListIterator::next(){
	if (!this->valid())
	{
		throw exception();
	}
	this->current += 1;
}

bool ListIterator::valid() const{
	if ((this->current > this->list.current_size - 1) || this->current < 0)
	{
		return false;
	}
	return true;
}

TComp ListIterator::getCurrent() const{

	return this->list.getElement(this->current);
}


