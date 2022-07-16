#include <assert.h>
#include "Matrix.h"
#include <iostream>
using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);

	//Extra feature test
    m.setMainDiagonal(2);
    assert(m.element(0,0) == 2);
    assert(m.element(1,1) == 2);
    assert(m.element(2,2) == 2);
    assert(m.element(3,3) == 2);
}