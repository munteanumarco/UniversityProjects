#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
    this->current = this->list.head;
}

void ListIterator::first(){
	this->current = this->list.head;
}

void ListIterator::next(){
	if (current == -1)
    {
	    throw exception();
    }
	this->current = this->list.next[current];
}

bool ListIterator::valid() const{
	return current != -1;
}

TComp ListIterator::getCurrent() const{
	if (current == -1)
    {
	    throw exception();
    }
	return this->list.elems[this->current];
}


