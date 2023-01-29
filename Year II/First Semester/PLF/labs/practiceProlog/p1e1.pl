/*
1.
a. Write a predicate to determine the lowest common multiple of a list 
formed from integer numbers.
b. Write a predicate to add a value v after 
1-st, 2-nd, 4-th, 8-th, ... element in a list.*/


/*
gcd(X,Y) = {
    X, Y = 0
    Y, X = 0
    gcd(X%Y, Y), X >= Y
    gcd(X, Y%X), Y > X
}

gcd(X - number, Y - number, R - result)
gcd(i,i,o)
*/

gcd(X,0,X) :- !.
gcd(0,Y,Y) :- !.
gcd(X,Y,R) :-
    X >= Y,
    X1 is X mod Y,
    gcd(X1, Y, R), !.
gcd(X,Y,R) :-
    X < Y,
    Y1 is Y mod X,
    gcd(X, Y1, R), !.
/*
 Model matematic:
 lcm(a, b) = a * b \/ gcd(a, b)

 lcm(A:number, B:number, R:number)
 lcm(i, i, o)*/

lcm(X, Y, R) :-
    gcd(X, Y, RG),
    R is X * Y / RG.


/*
lcmList(l1,l2,...,ln, C) = {
    0, n = 0
    l1, n = 1,
    lcmList(l3,...,ln, lcm(l1,l2)), otherwise 
}

lcmList(L - list, C - colector)
lcmList(i,o)

mainLcmList(l1,l2,...,ln) = {
    0, n = 0
    l1, n = 1
    lcmList(l3,...,ln,lcm(l1,l2)), otherwise
}

mainLcmList(L- list)
mainLcmList(i)

*/

lcmList([], _, _).
lcmList([H|T], C, R) :-
    lcm(C,H,RLCM),
    R is RLCM,
    lcmList(T, RLCM, R).

mainLcmList([], 0).
mainLcmList([H], H).
mainLcmList([H1,H2|T], R):-
    lcm(H1,H2,RLCM),
    lcmList(T, RLCM, R2),
    R is R2.


/*
insertAfter(l1,l2,...,ln,v,pos,n) = {
    [], n = 0
    l1 U insertAfter(l2,..,ln,v,pos+1,n), pos!=n
    V U l1 U insertAfter(l2,...,ln,v,pos+1,n*2), pos = n
}

insertAfter(L-list,V-number,P-number,N-number,R-result list)
insertAfter(i,i,i,i,o)

mainInsertAfter(l1,l2,...,ln,v) = {
    [], n = 0
    insertAfter(l1,l2,...,ln,v,0,1), otherwise
}
*/


insertAfter([],_,_,_,[]).
insertAfter([H|T],V,P,N,[V,H|R]) :-
    P == N,
    N1 is N*2,
    P1 is P+1,
    insertAfter(T,V,P1,N1,R).
insertAfter([H|T],V,P,N,[H|R]) :-
    P1 is P+1,
    insertAfter(T,V,P1,N,R).

mainInsertAfter([],_,[]).
mainInsertAfter(L,V,R) :-
    insertAfter(L,V,0,1,R).







