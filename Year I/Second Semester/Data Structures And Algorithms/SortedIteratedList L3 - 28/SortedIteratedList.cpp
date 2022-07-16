#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
#include <exception>

using namespace std;


SortedIteratedList::SortedIteratedList(Relation r) {
	this->relation = r;
	//empty list
    this->head = -1;
    this->cap = 100;

    //allocate arrays
	this->elems = new TComp[100];
	this->next = new TComp[100];
    for (int i = 0; i < 100; i++)
    {
        this->next[i] = i+1;
    }

    this->next[cap - 1] = -1;
    this->firstFree = 0;
    this->current_size = 0;
}

void SortedIteratedList::internal_search(TComp e, int &previous_node, int &current_node) const {

    ///Best case - search for something that should be before the head or the head itself - O(1)
    ///Worst/Average case - O(current_size)
    int current = this->head;
    previous_node = -1;
    current_node = current;
    int found = 0;
    while (current != -1 && this->relation(this->elems[current],e))
    {
        if (this->elems[current] == e)
        {
            found = 1;
            break;
        }
        previous_node = current_node;
        current = this->next[current];
        current_node = current;
    }
    if (!found)
    {
        current_node = -1;
    }
}

void SortedIteratedList::freeP(int pos) {
    this->next[pos] = this->firstFree;
    this->firstFree = pos;
}

int SortedIteratedList::size() const {
	return this->current_size;
}

bool SortedIteratedList::isEmpty() const {

    return this->head == -1;
}

ListIterator SortedIteratedList::first() const {

	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const {

    if (!poz.valid())
    {
        throw exception();
    }
    return poz.getCurrent();
}

TComp SortedIteratedList::remove(ListIterator& poz) {

    ///Best case - remove the head - O(1)
    ///Worst case/Average case - O(current_size)

	int position = poz.current;

	int current = this->head;
	int prev = -1;

	while (current != -1 && current != position)
    {
	    prev = current;
	    current = this->next[current];
    }

	if (current == -1)
    {
	    throw exception();
    }

	TComp removed_value = this->elems[position];

	if (position == this->head)
    {
	    this->head = this->next[this->head];
    }
	else
    {
	    this->next[prev] = this->next[current];
    }
	poz.current = this->next[position];
	this->freeP(position);
    this->current_size -= 1;

	return removed_value;
}

ListIterator SortedIteratedList::search(TComp e) const{

    ///Best case searching for the head or something that should be before the head - O(1)
    ///Worst/Average case - O(current_size)

    int previous = 0, current = 0;
    this->internal_search(e,previous,current);

    ListIterator it = ListIterator(*this);
    it.current = current;
    return it;
}

void SortedIteratedList::add(TComp e) {

    ///Best case - do not have to resize , adding head - O(1)
    ///Best/Average case - O(current_size)

    if (this->current_size == this->cap)
    {
        this->cap = 2 * this->cap;
        TComp* new_elems = new TComp[this->cap];
        TComp* new_next = new TComp[this->cap];

        for (int i = 0; i < this->current_size; i++)
        {
            new_elems[i] = this->elems[i];
            new_next[i] = this->next[i];
        }

        delete [] this->elems;
        delete [] this->next;

        this->elems = new_elems;
        this->next = new_next;

        for (int i = this->current_size; i < this->cap; i++)
        {
            this->next[i] = i+1;
        }

        this->next[this->cap-1] = -1;
        this->firstFree = this->current_size;
    }

    int current = 0, previous = 0;
    this->internal_search(e,previous,current);
    //the case we have to insert first
    if (previous == -1)
    {
        int position = this->firstFree;

        this->firstFree = this->next[this->firstFree];

        this->elems[position] = e;
        this->next[position] = this->head;
        this->head = position;
    }
    else
    {
        int position = this->firstFree;

        this->firstFree = this->next[this->firstFree];

        this->elems[position] = e;
        this->next[position] = this->next[previous];
        this->next[previous] = position;
    }

    this->current_size += 1;
}

SortedIteratedList::~SortedIteratedList() {
	delete [] this->elems;
	delete [] this->next;
}

void SortedIteratedList::print() {
    int current = this->head;

    while (current != -1)
    {
        cout << this->elems[current] <<" ";
        current = this->next[current];
    }
    cout << "\n";
}

int SortedIteratedList::removeFromKtoK(int k){

    ///Best case O(1)
    ///Average case O(current_size)
    ///Worst case O(current_size^2)
    if (k <= 0)
    {
        throw exception();
    }
    int removed_elems = 0;
    int i = 0;
    ListIterator it = this->first();

    while(it.valid())
    {
        if ((i+1) % k == 0)
        {
            this->remove(it);
            removed_elems ++;
        }
        else it.next();
        i++;
    }

    return removed_elems;
}


///Complexity Best case O(1) , Worst/Average case O(n)
void SortedIteratedList::empty() {

    ListIterator it = this->first();
    while(it.valid())
    {
        this->remove(it);
    }
}


