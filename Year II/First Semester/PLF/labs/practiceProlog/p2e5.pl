/*
 my_append(l1,l2,...,ln,c1,c2,...,cm, list) = {
    list , n = 0
    l1 + inserare(l2m,,,ln)
 }
*/


my_append([],L,L).
my_append([H|T],L,[H|R]):-
    my_append(T,L,R).


/*
    subst(l1,l2,...,ln,e,r1,r2,...,rm) = {
        [], n = 0
        r1,r2,...,rm U subst(l2,...,ln,e,r1,r2,...,rm), l1 = e
        l1 U subst(l2,...,ln,e,r1,r2,...,rm), otherwise
    }
*/


subst([],_,_,[]).
subst([H|T],E,S,[S|R]):-
    H =:= E,
    subst(T,E,S,R).
subst([H|T],E,S,[H|R]):-
    H =\= E,
    subst(T,E,S,R).

/*
maxlist(l1,l2,...,ln,C,R) = {
    C, n = 0
    maxlist(l2,l3,...,ln,)
}
*/


maxlist([],C,C).
maxlist([H|T], C, R):-
    H > C,
    C1 is H,
    maxlist(T,C1,R).
maxlist([H|T], C, R):-
    H =< C,
    maxlist(T,C,R).

