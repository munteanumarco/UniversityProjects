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
