/*
    invert(l1,l2,...,ln) = {
        [], n = 0
        invert(l2,...,ln) U l1, otherwise
    }
*/


/*
sumNL(l1,l2,...,ln,c1,c2,...,cm) = {
}
*/

my_append(E,[],[E]).
my_append(E,[H|T],[H|T1]):-
    my_append(E,T,T1).

invert([],[]).
invert([H|T], R):-
    invert(T, R1),
    my_append(H,R1,R).

sumNL([],[],T,[T]):- T=\=0.
sumNL([],[],_,[]).
sumNL([H1|T1],[],T,[Hs|R]):-
    Hs is H1 + T,
    sumNL(T1,[],0,R).
sumNL([],[H2|T2],T,[Hs|R]):-
    Hs is H2 + T,
    sumNL([],T2,0,R).
sumNL([H1|T1],[H2|T2], T, [Hs|R]):-
    S is H1 + H2 + T,
    Tn is S div 10,
    Hs is S mod 10,
    sumNL(T1,T2, Tn, R).

sum(L1,L2,R):-
    invert(L1,IL1),
    invert(L2,IL2),
    sumNL(IL1,IL2,0,R1),
    invert(R1,R).


/*
    sumSub(l1,l2,...,ln,C) = {
        [C], n = 0
        sum(C,l1) U sumSub(l2,...,ln,C), l1 is list
        sumSub(l2,...,ln,C), otherwise
    }
*/

sumSub([],C,C).
sumSub([H|T],C,R):-
    is_list(H),
    sum(C,H,RS),
    sumSub(T,RS,R).
sumSub([H|T],C,R):-
    not(is_list(H)),
    sumSub(T,C,R).


