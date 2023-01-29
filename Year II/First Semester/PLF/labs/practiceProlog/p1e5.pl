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


/*% union(a1...an, b1...bm) =
% 	[], n = 0 and m = 0
% 	a1 + union(remove_occurences(a1...an, a1), remove_occurences(b1...bm, a1)), n > 0
% 	union(b1...bm, []), n = 0

% union(A:list, B:list, R:list)
% union(i, i, o)*/

union([],[],[]).
union([H|T], B, [H|R]):-
    removeAtom([H|T], H, R1),
    removeAtom(B, H, R2),
    union(R1,R2,R).
union([],B,R):-
    union(B,[],R).