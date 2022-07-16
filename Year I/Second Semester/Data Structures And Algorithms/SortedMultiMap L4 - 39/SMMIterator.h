#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

    void insert(HashNode& node);
	HashNode* sorted_array;
	int capacity;
	int size;

    int current_key;
    int current_value;
public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

