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
testSet(l1,...,ln) = {
    true, n = 0
    false, countOccurences(l1) != 1
    testSet(l2,...,ln), otherwise
}
*/


testSet([]).
testSet([H|T]):-
    countOccurences([H|T],H,R),
    R == 1,
    testSet(T,R),!.

/*
removeKOccurences(l1,l2,...,ln,e,c) = {
    [], n = 0
    removeKOccurences(l2,...,ln,e,c+1), l1 = e and c < 3
    l1 U removeKOccurences(l2,...,ln,e,c), otherwise
}
*/


removeKOccurences([],_,_,[]).
removeKOccurences([H|T],E,C,R):-
    H == E,
    C < 3,
    C1 is C + 1,
    removeKOccurences(T,E,C1,R).
removeKOccurences([H|T],E,C,[H|R]):-
    H \== E,
    removeKOccurences(T,E,C,R).


