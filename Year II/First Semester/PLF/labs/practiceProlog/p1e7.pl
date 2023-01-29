present([H|_],E):-
    H == E,!.
present([_|T],E):-
    present(T,E).


/*
intersect(l1,l2,...,ln1,s1,s2,...,sn2) = {
    [], n1 = 0 || n2 = 0
    l1 U intersect(l2,...,ln,s1,...,sn), present(S,l1)
    intersect(l2,...,ln,s1,...,sn), otherwise
}
*/

intersect([],[],[]):-!.
intersect([],_,[]):-!.
intersect(_,[],[]):-!.
intersect([H|T],B,[H|R]):-
    present(B,H),!,
    intersect(T,B,R).
intersect([H|T],B,R):-
    not(present(B,H)),
    intersect(T,B,R).

/*
createMtoN(M,N) = {
    [N], M = N
    M U createMtoN(M+1,N).
}
*/

createMtoN(N,N,[N]).
createMtoN(M,N,[M|R]):-
    M1 is M + 1,
    createMtoN(M1,N,R).
