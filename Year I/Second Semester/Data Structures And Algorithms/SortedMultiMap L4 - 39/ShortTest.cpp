#include <assert.h>
#include <iostream>
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());


//	SortedMultiMap s = SortedMultiMap(relation1);
//    cout << "Hello World!\n";
//	s.add(0,1);
//    s.add(0,2);
//    s.add(4,1);
//    s.add(4,4);
//    s.add(5,1);
//    s.print();
//
//    SMMIterator itt =  s.iterator();
//    cout << "it : \n";
//    itt.print();
//
//    itt.first();
//    int c = 0;
//
//    while (itt.valid()) {
//        cout << itt.getCurrent().first << "," << itt.getCurrent().second << "\n";
//        c++;
//        itt.next();
//    }
//    cout << c << " : size " << s.size();
}

