#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

using namespace std;

SortedBag::SortedBag(Relation r) {
	this->r = r;
	this->capacity = 100;
	this->current_size = 0;
	this->distinct_size = 0;
	this->bst = new BSTNode[100];
	this->root = -1;
	this->firstFree = 0;
}

///Complexity: Worst case O(n) chain tree
///            Average case O(log n)
void SortedBag::add(TComp e) {
	if (this->firstFree >= this->capacity || this->current_size == this->capacity)
    {
	    this->resize();
    }
	this->bst[this->firstFree].info = e;
	int current = this->root, parent = -1;
	bool found = false;
	while (current != -1) {
	    parent = current;
	    if (this->r(e, this->bst[current].info)) {
	        if (this->bst[current].info == e) {
                found = true;
                break;
            }
	        else {
                current = this->bst[current].left;
	        }
	    }
	    else
        {
	        current = this->bst[current].right;
        }
	}


    if (this->root == -1) {
        this->root = this->firstFree;
        this->bst[this->root].frequency = 1;
        this->nextFirstFree();
        this->distinct_size += 1;
    }
	else {
        if (found) {
            this->bst[current].frequency += 1;
        }
        else {
                if (this->r(e, this->bst[parent].info)) {
                    this->bst[parent].left = this->firstFree;
                    this->bst[this->bst[parent].left].info = e;
                    this->bst[this->bst[parent].left].frequency = 1;
                } else {
                    this->bst[parent].right = this->firstFree;
                    this->bst[this->bst[parent].right].info = e;
                    this->bst[this->bst[parent].right].frequency = 1;
                }
                this->nextFirstFree();
                this->distinct_size += 1;
            }
	}
    this->current_size += 1;
}


///Complexity Worst case O(n) chain tree
///           Average case O(log n)
bool SortedBag::remove(TComp e) {

	bool removed = false;
	this->root = this->removeRecursively(this->root, e, removed);
	if (removed) {
	    this->current_size -= 1;
	}
	return removed;
}

///Complexity Worst case O(n) chain tree
///           Average case O(log n)
bool SortedBag::search(TComp elem) const {
    int current = this->root;
    while (current != -1) {
        if (this->r(elem, this->bst[current].info)) {
            if (this->bst[current].info == elem) {
                return true;
            }
            else {
                current = this->bst[current].left;
            }
        }
        else
        {
            current = this->bst[current].right;
        }
    }
    return false;
}

///Complexity Worst case O(n) chain tree
///           Average case O(log n)
int SortedBag::nrOccurrences(TComp elem) const {
    int current = this->root;
    int occurrences = 0;
    while (current != -1) {
        if (this->r(elem, this->bst[current].info)) {
            if (this->bst[current].info == elem) {
                occurrences = this->bst[current].frequency;
                break;
            }
            else {
                current = this->bst[current].left;
            }
        }
        else
        {
            current = this->bst[current].right;
        }
    }
    return occurrences;
}


///Complexity O(1)
int SortedBag::size() const {
	return this->current_size;
}

///Complexity O(1)
bool SortedBag::isEmpty() const {
	return this->current_size == 0;
}

///Complexity O(1)
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	delete [] this->bst;
}

void SortedBag::resize() {
    this->capacity *= 2;
    BSTNode *new_bst = new BSTNode[this->capacity];
    for (int i = 0; i < this->current_size; i++)
    {
        new_bst[i] = this->bst[i];
    }

    delete [] this->bst;
    this->bst = new_bst;
}

void SortedBag::nextFirstFree() {
    this->firstFree += 1;
    while (this->firstFree < this->capacity && this->bst[this->firstFree].info != NULL_TCOMP) {
        this->firstFree += 1;
    }
}

int SortedBag::removeRecursively(int node, TComp e, bool &removed) {
    if (node == -1) {
        return node;
    }

    if (this->bst[node].info == e) {
        removed = true;

        if (this->bst[node].frequency > 1) {
            this->bst[node].frequency -= 1;
        }
        else if (this->bst[node].left == -1 && this->bst[node].right == -1) {
            node = -1;
            return node;
        }
        else if (this->bst[node].left == -1) {
            node = this->bst[node].right;
            return node;
        }
        else if (this->bst[node].right == -1) {
            node = this->bst[node].left;
            return node;
        }
        else {
            int maxNode = this->getMaximum(this->bst[node].left);
            this->bst[node].info = this->bst[maxNode].info;
            this->bst[node].left = this->removeRecursively(this->bst[node].left, this->bst[maxNode].info, removed);
        }
    }

    if (this->r(e, this->bst[node].info)) {
        this->bst[node].left = this->removeRecursively(this->bst[node].left, e, removed);
    }
    else if (!this->r(e, this->bst[node].info)){
        this->bst[node].right = this->removeRecursively(this->bst[node].right, e, removed);
    }

    return node;
}

int SortedBag::getMaximum(int root) {
    int current = root, maxNode = root;

    while(current != -1) {
        maxNode = current;
        current = this->bst[current].right;
    }
    return maxNode;
}

int SortedBag::distinctCount() const {
    return this->distinct_size;
}
