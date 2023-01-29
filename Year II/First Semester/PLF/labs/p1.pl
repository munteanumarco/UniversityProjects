/*
substitute(l1,l2,..ln,e,s1,s2,..sn) = 
{
    [], n = 0
    s1,s2,...,sn U substitute(l2,...,ln,e,s1,s2,...,sn), l1 = e
    l1 U substitute(l2,...,ln,e,s1,s2,...,sn), otherwise
}
*/

/* removeNth(l1,l2,..,ln,pos,n) = 
{
    [], n = 0
    l1 U removeNth(l2,...,ln,pos+1,n), pos != n
    removeNth(l2,...,ln,pos+1,n), otherwise
}
 */

 /* removeNth(l1,l2,..,ln,pos) = 
{
    [], n = 0
    removeNth(l2,...,ln,pos+1), pos mod 2 = 0
    l1 U removeNth(l2,...,ln,pos+1), otherwise
}
 */

%append(L1- initial list, R2-resulted list, L2-list to append)
append(R,R,[]).
append([H|R],R2,[H|T]):-
    append(R,R2,T).

%substitute(L1-initial list, EL-element to be replaced, L-list to replace the element, R-resulted list)
substitute([],_,[_|_],[]).
substitute([H|T],EL,L,R):-
    H=:=EL,
    append(R,R2,L),
    !,
    substitute(T,EL,L,R2).
substitute([H|T],EL,L,[H|R]):-
    substitute(T,EL,L,R).


%remove(A-initial list, POS-current position, N-position to remove, R-resulted list)
removeNth([],_,_,[]).
removeNth([H|T],POS,N,[H|R]):-
    N=\=POS,
    !,
    POS1 is POS+1,
    removeNth(T,POS1,N,R).
removeNth([_|T],POS,N,R):-
    POS1 is POS+1,
    removeNth(T,POS1,N,R).

%remove(A-initial list, N-position, R-resulted list)
remove(A,N,R):-
    removeNth(A,1,N,R).