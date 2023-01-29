/*
present(l1,l2,...,ln,e) = {
    false, n = 0
    true, l1 = e
    present(l2,...,ln,e),otherwise
}
*/

present([H|_],E):-
    H == E.
present([H|T],E):-
    H \== E,
    present(T,E).


/*
diffSets(l11,l12,...,l1n1, l21,l22,...,l2n2) = {
    l11,l12,...,l1n1, n2 = 0
    [], n1 = 0
    l1 U diffSets(l12,...,l1n, l21,l22,...,l2n, not(present(l21,...,l2n, l1))
    diffSets(l12,...,l1n, l21,l22,...,l2n, not_present(l21,...,l2n, l1), otherwise
}
*/

diffSets([],_,[]).
diffSets(A,[],A).
diffSets([H|T],B,[H|R]):-
    not(present(B,H)),
    diffSets(T,B,R).
diffSets([H|T],B,R):-
    present(B,H),
    diffSets(T,B,R).

/*
addE(l1,l2,...,ln) = {
    [], n = 0
    l1 U 1 U addE(l2,...,ln), l1 is even
    l1 U addE(l2,...,ln), otherwise
}
*/

addE([],[]).
addE([H|T],[H,1|R]):-
    H mod 2 =:= 0,
    addE(T,R).
addE([H|T],[H|R]):-
    H mod 2 =\= 0,
    addE(T,R).
