#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->stack = new int[100];
	this->capacity = 100;
	this->current_size = 0;
	this->first();
}

TComp SortedBagIterator::getCurrent() {
	if (!this->valid()) {
		throw exception();
	}
	return this->bag.bst[currentNode].info;
}

bool SortedBagIterator::valid() {
	return this->currentNode != -1;
}

void SortedBagIterator::next() {
	if (!valid()) {
		throw exception();
	}

	if (this->currentNodeFreq == 0) {
		int node = this->pop();
		if (this->bag.bst[node].right != -1) {
			node = this->bag.bst[node].right;
			while (node != -1) {
					this->push(node);
					node = this->bag.bst[node].left;
			}
		}

		if (this->current_size != 0) {
			this->currentNode = this->top();
			this->currentNodeFreq = this->bag.bst[this->currentNode].frequency - 1;
		}
		else {
			this->currentNode = -1;
		}
	}
	else {
		this->currentNodeFreq -= 1;
	}
}

void SortedBagIterator::first() {
	this->empty();
	this->currentNode = this->bag.root;

	while (this->currentNode != -1) {
			this->push(this->currentNode);
			this->currentNode = this->bag.bst[currentNode].left;
	}

	if (this->current_size != 0) {
		this->currentNode = this->top();
		this->currentNodeFreq = this->bag.bst[this->currentNode].frequency - 1;
	}
	else {
		this->currentNode = -1;
		this->currentNodeFreq = 0;
	}
}

void SortedBagIterator::push(int data) {
	if (this->current_size == this->capacity) {
		this->resize();
	}
	this->stack[this->current_size] = data;
	this->current_size += 1;
}

int SortedBagIterator::top() {
	if (this->current_size > 0) {
		return this->stack[this->current_size - 1];
	}
}

int SortedBagIterator::pop() {
	if (this->current_size > 0) {
		int elem = this->stack[this->current_size - 1];
		this->current_size -= 1;
		return elem;
	}
}

void SortedBagIterator::resize() {
	this->capacity *= 2;
	int* new_stack = new int[this->capacity];
	for (int i = 0; i < this->current_size; i++) {
		new_stack[i] = this->stack[i];
	}
	delete [] this->stack;
	this->stack = new_stack;
}

void SortedBagIterator::empty() {
	this->current_size = 0;
}



