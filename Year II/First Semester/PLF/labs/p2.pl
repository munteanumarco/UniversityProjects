/*
doublePrimes(l1,l2,...,ln) = 
{
    [], n = 0
    doublePrimes(l2,...,ln), prime(l1)
    l1 U doublePrimes(l2,...,ln), otherwise
}
*/

/*
doublePrimesInside(l1,l2,...,ln) = 
{
    [], n = 0
    l1 U doublePrimesInside(l2,l3,...,ln), l1 is not list
    doublePrimes(l1) U doublePrimesInside(l2,l3,...,ln), otherwise
}
*/

divisible(X,Y):- 
    X mod Y =:= 0,!.
divisible(X,Y):- 
    X>Y+1,
    Y1 is Y+1,
    divisible(X,Y1).

prime(2):-!.
prime(X):- 
    X<2,!,
    false.
prime(X):-
    not(divisible(X,2)).

%doublePrimes(L-initial list, R-resulted list)
doublePrimes([],[]).
doublePrimes([H|T],[H,H|R]):-
    prime(H),
    !,
    doublePrimes(T,R).
doublePrimes([H|T],[H|R]):-
    doublePrimes(T,R).

%doublePrimesInside(L-initial list, R-resulted list)
doublePrimesInside([],[]).
doublePrimesInside([H|T],[HR|R]):- 
    is_list(H),
    !,
    doublePrimes(H, HR),
    doublePrimesInside(T,R).
doublePrimesInside([H|T],[H|R]):-
    doublePrimesInside(T,R).


