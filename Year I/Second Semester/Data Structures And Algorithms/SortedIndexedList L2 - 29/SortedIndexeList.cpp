#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

DLLNode::DLLNode(TComp info) {
    this->info = info;
    this->next = NULL;
    this->prev = NULL;
}


SortedIndexedList::SortedIndexedList(Relation r) {
	this->rel = r;
	this->current_size = 0;
	this->head = NULL;
	this->tail = NULL;
}

int SortedIndexedList::size() const {
    return this->current_size;
}

bool SortedIndexedList::isEmpty() const {

	return this->current_size == 0;
}

TComp SortedIndexedList::getElement(int i) const{
	if (i < 0 || i > this->current_size-1)
    {
	    throw exception();
    }
    ///Average complexity  as we search from the head or from the tail based on the given 'i' - O(current_size/2) - linear
    ///Best case when the position is either 0 or current_size - 1 or invalid 'i' - O(1) - constant

    // if the position is in the first half of the list then we begin from the head
	if (i < this->current_size/2)
	{
	    DLLNode* current_element = this->head;
	    for (int k = 0; k != i; k++)
        {
	        current_element = current_element->next;
        }
	    return current_element->info;
    }
	else
    {   // if the position is in the second half of the list then we begin from the tail and we go backwards
	    DLLNode* current_element = this->tail;
	    for (int k = this->current_size-1; k != i; k--)
        {
	        current_element = current_element->prev;
        }
        return current_element->info;
    }

}

TComp SortedIndexedList::remove(int i)
{
    ////Best case complexity when we have to delete either the head or the tail - O(1) - constant
    ///Average case complexity we have to iterate through the elements and get to position 'i' - O(current_size) - linear

    if (i < 0 || i > this->current_size-1)
    {
        throw exception();
    }

    TComp removed_element;
    if (i == 0)
    {
        //Remove the head
        //Check if the head is only element
        if (this->head == this->tail)
        {
            removed_element = this->head->info;
            delete this->head;
            delete this->tail;
            this->head = this->tail = NULL;
        }
        else
        {
            removed_element = this->head->info;
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = NULL;
        }
    }
    else
        if (i == this->current_size-1)
        {
            removed_element = this->tail->info;
            this->tail = this->tail->prev;
            delete this->tail->next;
            this->tail->next = NULL;
        }
        else
        {
            DLLNode* current_element = this->head;
            for (int k = 0; k != i; k++)
            {
                current_element = current_element->next;
            }

            removed_element = current_element->info;

            current_element->prev->next = current_element->next;
            current_element->next->prev = current_element->prev;

            delete current_element;
        }

    this->current_size -= 1;
    return removed_element;
}

int SortedIndexedList::search(TComp e) const {

    ///Average/Worst case complexity O(current_size) - linear , worst case when search for the last element
    ///Best case we search for the first element - O(1) - constant

    DLLNode* current_element = this->head;
    for (int i = 0; i < this->current_size; i++)
    {
        if (current_element->info == e)
        {
            return i;
        }
        current_element = current_element->next;
    }

    return -1;
}

void SortedIndexedList::add(TComp e) {

    ////Best case complexity when we have to add  the head - O(1) - constant
    ///Average case complexity we have to iterate through the elements and get to position 'i' where to insert - O(current_size) - linear

    DLLNode* new_node = new DLLNode();
    new_node->info = e;

    if (this->head == NULL)
    {
        this->head = new_node;
        this->head->next = NULL;
        this->head->prev = NULL;
        this->tail = this->head;
    }
    else
    {
        //Find where we need to insert
        DLLNode* current_node = this->head;
        int i = 0;
        while ((i < this->current_size) && this->rel(current_node->info,e))
        {
            if (current_node->next != NULL)
            {
                current_node = current_node->next;
            }
            i++;
        }
        int index = i-1;

        //check if we reach the end so we have to insert at the end
        if (i != this->current_size)
        {
            current_node = current_node->prev;
        }
        //we need to insert after the index
        if (index == -1)
        {
            //we must insert new head;
            this->head->prev = new_node;
            new_node->next = this->head;
            this->head = this->head->prev;
            this->head->prev = NULL;
        }
        else
            if (index == this->current_size-1)
            {
                current_node->next = new_node;
                new_node->prev = current_node;
                new_node->next = NULL;
                this->tail = new_node;
            }
            else
            {
                //insert after the found one
                new_node->next = current_node->next;
                current_node->next->prev = new_node;
                current_node->next = new_node;
                new_node->prev = current_node;
            }

    }

    this->current_size += 1;
}

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}


int SortedIndexedList::removeFromKtoK(int k){

    if (k <= 0)
    {
        throw exception();
    }

}

//destructor
SortedIndexedList::~SortedIndexedList() {

    DLLNode* temp;
    while(this->head != NULL) {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

}

