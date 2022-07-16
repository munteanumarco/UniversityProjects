#include "Matrix.h"
#include <exception>
#include <iostream>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	this->nr_of_lines = nrLines;
	this->nr_of_cols = nrCols;

	this->lines = new TElem[nrLines+1];

	//Set initial value for the lines array to 0
	for (int i = 0; i < nrLines + 1; i++)
    {
	    this->lines[i] = NULL_TELEM;
    }

	this->col = new TElem[10];
	this->value = new TElem[10];

	this->size = 0;
	this->capacity = 10;
}


int Matrix::nrLines() const {

    return this->nr_of_lines;
}


int Matrix::nrColumns() const {

    return this->nr_of_cols;
}


TElem Matrix::element(int i, int j) const {
    /**
     * Complexity of the function
     * Worst/Average Case (we have to iterate through all elements on a line and get the one situated on last column) - O(nr_of_cols)
     * Best case (either the (i,j) is out of bounds or we search for the first element on the line)  - O(1)
     **/

    if (i < 0 || i > (this->nr_of_lines - 1) || j < 0 || j > (this->nr_of_cols - 1)) {
        throw exception();
    }

    for (int k = this->lines[i]; k < this->lines[i + 1]; k++)
    {
        if (this->col[k] == j)
        {
            return this->value[k];
        }
        if (this->col[k] > j)
        {
            return NULL_TELEM;
        }
    }

    return NULL_TELEM;
}


TElem Matrix::modify(int i, int j, TElem e) {

    /**
     * Complexity of the function
     *  if the element already exists in the value and col arrays => Worst/Average case - O(nr_of_cols) and best case O(1)
     *  if we need to insert the element => Worst/Average case - O(nr_of_cols + size + nr_of_lines)
     **/

    if (i < 0 || i > (this->nr_of_lines - 1) || j < 0 || j > (this->nr_of_cols - 1)) {
        throw exception();
    }

    ///Complexity -  O(nr_of_cols)
    TElem current = this->element(i,j);

    if (current == NULL_TELEM)
    {
        //Find the index  in cols and value and insert after it
        int index = 0;
        ///Complexity - O(nr_of_cols)
        for (index = this->lines[i]; index < this->lines[i + 1]; index++)
        {
            if (this->col[index] > j)
            {
                break;
            }
        }

        index-=1;


        //Check if the dynamic arrays are full and resize;
        if (this->size == this->capacity)
        {
            this->capacity = 2 * this->capacity;
            TElem* new_col = new TElem[this->capacity];
            TElem* new_value = new TElem[this->capacity];

            ///Complexity O(size)
            for (int t = 0; t < this->size; t++)
            {
                new_col[t] = this->col[t];
                new_value[t] = this->value[t];
            }

            delete [] this->col;
            delete [] this->value;

            this->col = new_col;
            this->value = new_value;
        }

        for (int t = this->size-1; t > index; t--)
        {
            this->value[t+1] = this->value[t];
            this->col[t+1] = this->col[t];
        }

        this->col[index+1] = j;
        this->value[index+1] = e;

        this->size += 1;


        //Update lines array by incrementing all elements up from i+1
        ///Complexity O(nr_of_lines)
        for (int t = i + 1 ; t < this->nr_of_lines+1; t++)
        {
            this->lines[t] += 1;
        }

        return NULL_TELEM;
    }
    else
    {
        //Modify the already existing element in the value array
        ///Complexity -  O(nr_of_cols)
        for (int k = this->lines[i]; k < this->lines[i + 1]; k++)
        {
            if (this->col[k] == j)
            {
                TElem  old_value = this->value[k];
                this->value[k] = e;
                return old_value;
            }
        }
    }

}

void Matrix::setMainDiagonal(TElem elem)
{
    ///Complexity O(nr_of_cols * (2*nr_of_cols + size)) for square matrix will be quadratic O(nr_of_cols^2)
    if (this->nr_of_lines != this->nr_of_cols) {
        throw exception();
    }
    for (int i = 0; i < this->nr_of_lines; i++)
    {
        this->modify(i,i,elem);
    }
}

Matrix::~Matrix() {

    delete [] this->lines;
    delete [] this->col;
    delete [] this->value;
}

