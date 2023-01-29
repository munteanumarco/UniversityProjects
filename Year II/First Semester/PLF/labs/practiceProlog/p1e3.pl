
/*
countOccurences(l1,l2,...,ln,e) = {
    0, n =0
    1 + countOccurences(l2,...,ln,e), l1 = e
    countOccurences(l2,...,ln,e), otherwise
}
*/

countOccurences([],_,0).
countOccurences([H|T],E,R):-
    H =:= E,
    countOccurences(T,E,R1),
    R is R1 + 1.
countOccurences([H|T],E,R):-
    H =\= E,
    countOccurences(T,E,R).


/*
removeAtom(l1,l2,...,ln,v) = {
    [], n = 0
    removeAtom(l2,...,ln,v), atom(l1) and l1 = v
    l1 U removeAtom(l2,...,ln,v), otherwise
}

*/

removeAtom([],_,[]).
removeAtom([H|T],V, [H|R]) :-
    H \== V,
    removeAtom(T,V,R).
removeAtom([H|T],V, R) :-
    H == V,
    removeAtom(T,V,R). 

/*
removeRep(l1,l2,...,ln) = {
    [], n = 0
    l1 U removeRep(l2,...,ln), countOccurences(l2,...,ln,l1) = 0
    removeRep(l2,...,ln), otherwise
}
*/


removeRep([],[]).
removeRep([H|T],[H|R]):-
    countOccurences(T,H, RC),
    RC == 0,
    removeRep(T,R).
removeRep([H|T],R):-
    countOccurences(T,H, RC),
    RC \== 0,
    removeAtom(T,H,RA),
    removeRep(RA,R).
