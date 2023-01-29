#include "lista.h"
#include <iostream>

/**
 * evenNumberOfElements(l1,l2, .. ln) = {
 *         true, n = 0
 *         false, n = 1
 *         evenNumberOfElements(l3, .. , ln), otherwise
 *  }
 * **/

bool evenNumberOfElements(PNod node) {
    if (node == NULL) {
        return true;
    }
    if (node->urm == NULL) {
        return false;
    }
    evenNumberOfElements(node->urm->urm);
}

/**
 * deleteAllOccurrences (l1,l2,...,ln,  e) = {
 *      [] , l is empty
 *      deleteAllOccurrences(l2,...,ln,, e) , l1=e
 *      [l1] U deleteAllOccurrences(l2,...,ln, e) , l1 != e
 * }
 * **/

/**
 * deleteFirstOccurrence (l1,l2,...,ln,  e) = {
 *      [] , l is empty
 *      [l2, l3, .., ln] , l1=e
 *      [l1] U deleteFirstOccurrence(l2,...,ln, e) , l1 != e
 * }
 * **/

void deleteAllOccurrences(Lista& l, PNod currentNode, PNod prevNode, TElem e) {
    if (currentNode == NULL) {
        return;
    }
    if (currentNode->e == e) {
        if (prevNode == NULL) {
            l._prim = currentNode->urm;
            deleteAllOccurrences(l, currentNode->urm, NULL, e);
        }
         else {
             prevNode->urm = currentNode->urm;
             deleteAllOccurrences(l, currentNode->urm, prevNode, e);
         }
         return;
    }
    deleteAllOccurrences(l, currentNode->urm, currentNode, e);
}



int main()
{
   Lista l;
   l=creare();
   tipar(l);
   //std::cout << "\n" << evenNumberOfElements(l._prim) << "\n";
   deleteAllOccurrences(l, l._prim, NULL, 2);
   std::cout << "\n";
   tipar(l);

}
