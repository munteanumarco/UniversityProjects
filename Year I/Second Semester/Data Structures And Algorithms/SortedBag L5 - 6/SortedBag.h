#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111
class SortedBagIterator;

class BSTNode {
public:
    int left;
    int right;
    TComp info;
    int frequency;
    BSTNode(TComp info = NULL_TCOMP, int freq = 0, int left = - 1, int right = -1): info(info), frequency(freq), left(left), right(right) {};
};

class SortedBag {
	friend class SortedBagIterator;

private:
	BSTNode *bst;
	int root;
	int capacity;
	int current_size;
	int distinct_size;
	int firstFree;
    Relation r;
    void resize();
    void nextFirstFree();
    int removeRecursively(int node, TComp e, bool &removed);
    int getMaximum(int root);
public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
    ///Complexity: Worst case O(n) chain tree
    ///            Average case O(log n)
	void add(TComp e);

	//removes one occurrence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)
    ///Complexity: Worst case O(n) chain tree
    ///            Average case O(log n)
	bool remove(TComp e);

	//checks if an element appears in the sorted bag
    ///Complexity: Worst case O(n) chain tree
    ///            Average case O(log n)
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
    ///Complexity: O(1)
	int nrOccurrences(TComp e) const;


	//returns the number of elements from the sorted bag
    ///Complexity: O(1)
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

    //counts and returns the number of distinct elements in the SortedBag
    int distinctCount() const;

    //destructor
	~SortedBag();

};