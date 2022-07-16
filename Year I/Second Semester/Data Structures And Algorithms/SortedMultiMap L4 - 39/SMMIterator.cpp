#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>

///Complexity Best case - O(1)
///Average/Worst case - O(n)
void SMMIterator::insert(HashNode& node) {

	if (this->size == this->capacity)
	{
		this->capacity *= 2;
		HashNode* new_array = new HashNode[this->capacity];

		for (int i = 0; i < this->size; i++)
		{
			new_array[i] = this->sorted_array[i];
		}

		delete [] this->sorted_array;

		this->sorted_array = new_array;
	}

	int i = 0;
	while (i < this->size && this->map.relation(this->sorted_array[i].key,node.key))
	{
		i++;
	}

	if (i == this->size)
	{
		this->sorted_array[i] = node;
		this->size += 1;
	}
	else
	{
		for (int j = this->size; j > i; j--)
		{
			this->sorted_array[j] = this->sorted_array[j-1];
		}

		sorted_array[i] = node;

		this->size += 1;
	}

}
///Complexity Best Case/Average case - O(n)
///Complexity Worst Case - O(n^2)
SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	this->current_key = 0;
	this->current_value = 0;
	this->sorted_array = new HashNode[100];
	this->capacity = 100;
	this->size = 0;

	for (int i = 0; i < this->map.capacity; i++)
	{
		if (this->map.elements[i].key != NULL_TKEY)
		{
			this->insert(this->map.elements[i]);
		}
	}
}
///Complexity O(1)
void SMMIterator::first(){
	this->current_key = current_value = 0;
}
///Complexity O(1)
void SMMIterator::next(){

	if (current_key == this->size)
	{
		throw exception();
	}

	if (this->current_value < this->sorted_array[current_key].size - 1)
	{
		this->current_value += 1;
	}
	else
	{
		this->current_key += 1;
		this->current_value = 0;
	}
}
///Complexity O(1)
bool SMMIterator::valid() const{
	return this->current_key < this->size;
}
///Complexity O(1)
TElem SMMIterator::getCurrent() const{

	if (this->current_key == this->size)
	{
		throw exception();
	}

	TKey k = this->sorted_array[this->current_key].key;
	TValue v = this->sorted_array[this->current_key].values[this->current_value];
	TElem t;
	t.first = k;
	t.second = v;
	return t;
}




