/*

evenElem(l1,l2,...,ln) = {
    true, n = 0
    evenElem(l3,...,ln), exists l1 and l2
}

*/

evenElem([]).
evenElem([_,_|T]):-
    evenElem(T).

/*
minimum(l1,l2,...,ln) = {
    [], n = 0
    l1, l1 < minimum(l2,...,ln)
    minimum(l2,...,ln), otherwise
}
*/

min_numbers(A, B, A):- A =< B.
min_numbers(A, B, B):- A > B.

minim_list([H], H).
minim_list([H|T], R):-
    minim_list(T, R1),
    min_numbers(H,R1,R).

/*
deleteFirst(l1,l2,...,ln,d) = {
    [], n = 0
    deleteFirst(l2,...,ln,d), d = 0 and l1 == minimum(l1,...,ln)
    l1 U deleteFirst(l2,...,ln,d), otherwise
}
*/

deleteFirst([],_,[]).
deleteFirst([H|T],D,R):-
    minim_list([H|T])

deleteFirstMain(L,R):-
    deleteFirst(L,0,R).



