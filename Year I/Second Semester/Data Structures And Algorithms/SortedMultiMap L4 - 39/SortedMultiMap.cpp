#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

HashNode::HashNode(TKey key)
{
    this->key = key;
    this->cap = 5;
    this->values = new TValue[this->cap];
    this->size = 0;
}
///Complexity O(n)
void HashNode::resize()
{
    TValue* new_vals = new TValue[this->cap*2];
    for (int i = 0; i < this->cap; i++)
    {
        new_vals[i] = this->values[i];
    }

    delete [] this->values;
    this->values = new_vals;
    this->cap *= 2;
}

///Complexity Best case/Average case - O(1)
///           Worst case - resize - O(n)
void HashNode::add(int value)
{
    if (this->size == this->cap)
    {
        this->resize();
    }

    this->values[this->size] = value;
    this->size += 1;
}


/// Best case - O(1)
/// Average/Worst case - O(n)
void HashNode::remove(int index)
{
    for (int i = index; i < this->size - 1; i++)
    {
        this->values[i] = this->values[i+1];
    }
    this->size -= 1;
}
HashNode::~HashNode()
{
    delete [] this->values;
}

SortedMultiMap::SortedMultiMap(Relation r)
{
	this->relation = r;
	this->capacity = 100;
	this->current_size = 0;
	this->elements = new HashNode[100];

	this->prime = this->capacity-1;
	/* Find the largest prime number smaller than hash table's size. */
	while (!this->isPrime(this->prime))
	{
		this->prime -= 1;
	}

}
/// Complexity O(1)
int SortedMultiMap::hash1(int value) const
{
	return (value % this->capacity);
}
/// Complexity O(1)
int SortedMultiMap::hash2(int value) const
{
	return (this->prime - (value % this->prime));
}
/// Complexity O(1)
int SortedMultiMap::probe(int value, int i) const
{
    return (this->hash1(value) + i*hash2(value)) % this->capacity;
}

///Complexity Best case - O(1)
/// Average/Worst case - O(sqrt of n)
int SortedMultiMap::isPrime(int number) {

	if (number < 2 || number > 2 && number%2 == 0)
	{
		return 0;
	}
	for(int d = 3; d*d <= number; d += 2)
	{
		if (number%d == 0)
		{
			return 0;
		}
	}
	return 1;
}
///Complexity Best case - O(old_cap)
/// Worst/Average case - O(old_cap * new_cap)
void SortedMultiMap::resize_rehash()
{
    int old_cap = this->capacity;
    this->capacity *= 2;

    this->prime = this->capacity-1;
    /* Find the largest prime number smaller than hash table's size. */
    while (!this->isPrime(this->prime))
    {
        this->prime -= 1;
    }
    HashNode* new_elems = new HashNode[this->capacity];
    for (int i = 0; i < old_cap; i++)
    {
        if (this->elements[i].key != NULL_TKEY)
        {
            int j = 0;
            int index = this->probe(this->elements[i].key,j);
            while(new_elems[index].key != NULL_TKEY && new_elems[index].key != this->elements[i].key)
            {
                j++;
                index = this->probe(this->elements[i].key,j);
            }
            new_elems[index].key = this->elements[i].key;
            for (int j = 0; j < this->elements[i].size; j++)
            {
                new_elems[index].add(elements[i].values[j]);
            }
        }
    }

    delete [] this->elements;
    this->elements = new_elems;

}

///Complexity Best case/Average case - O(1)
///Worst case O(n)
void SortedMultiMap::add(TKey c, TValue v)
{

	if ((float)(this->current_size/this->capacity) >= this->load_factor)
	{
		this->resize_rehash();
	}
    int i = 0;
	int index = this->probe(c,i);
	//keep probing till we find an empty slot or the key itself
    while(this->elements[index].key != NULL_TKEY && this->elements[index].key != c)
    {
        i++;
        index = this->probe(this->elements[i].key,i);
    }

    this->elements[index].key = c;
    this->elements[index].add(v);
    this->current_size += 1;

}

///Complexity Best Case/Average Case - O(1)
/// Worst case O(n)
vector<TValue> SortedMultiMap::search(TKey c) const
{
	vector<TValue> result;

    int i = 0;
    int index = this->probe(c,i);
    //keep probing till we find an empty slot or the key itself
    while(this->elements[index].key != NULL_TKEY && this->elements[index].key != c)
    {
        i++;
        index = this->probe(this->elements[i].key,i);
    }

    if (this->elements[index].key == c)
    {
        for (int i = 0; i < this->elements[index].size; i++)
        {
            result.push_back(this->elements[index].values[i]);
        }
    }
    return result;
}

///Complexity Best Case - O(1)
///Worst/Average Case - O(n)

bool SortedMultiMap::remove(TKey c, TValue v)
{
	if (this->search(c).size() == 0)
    {
	    return false;
    }

	int i = 0;
	int index = this->probe(c,i);
	while(this->elements[index].key != c)
    {
	    i++;
	    this->probe(c,i);
    }
	int found = 0;
	int j;
	for (j = 0; j < this->elements[index].size; j++)
    {
	    if (this->elements[index].values[j] == v)
        {
	        found = 1;
	        break;
        }
    }

	if (!found)
    {
	    return false;
    }

	if (this->elements[index].size == 1)
    {
	    this->elements[index].key = NULL_TKEY;
	    this->elements[index].remove(0);
    }
	else
    {
	    this->elements[index].remove(j);
    }
    this->current_size -= 1;
    return true;
}

///Complexity O(1)
int SortedMultiMap::size() const
{
	return this->current_size;
}
///Complexity O(1)
bool SortedMultiMap::isEmpty() const
{
	return this->current_size == 0;
}
///Complexity O(1)
SMMIterator SortedMultiMap::iterator() const
{
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap()
{
	delete [] this->elements;
}