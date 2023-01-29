/*
merge(l1,l2,...,ln,c1,c2,...,cm) = {
    [], n = 0 & m = 0
    l1 U merge(l2,...,ln,c1,...,cm), l1 <= c1
    c1 U merge(l1,...,ln,c2,...,cm), otherwise
}
*/


merge([],[],[]).
merge([H1|T1],[],[H1|R]):-
    merge(T1,[],R).
merge([],[H2|T2],[H2|R]):-
    merge([],T2,R).
merge([H1|T1], [H2|T2], [H1|R]):-
    H1 =< H2,
    merge(T1,[H2|T2],R).
merge([H1|T1], [H2|T2], [H2|R]):-
    H1 > H2,
    merge([H1|T1],T2,R).

removeDoubles([],[]).
removeDoubles([H],[H]).
removeDoubles([H1,H2|T],[H1|R]):-
    H1 =\= H2,
    removeDoubles([H2|T], R).
removeDoubles([H1,H2|T], R):-
    H1 =:= H2,
    removeDoubles([H2|T], R).


main(L1,L2,R):-
    merge(L1,L2,RM),
    removeDoubles(RM,RR),
    R = RR.


/*
    mergeSub(l1,l2,...,ln, C) = {
        [C], n = 0
        merge(C,l1) U mergeSub(l2,...,ln,C), l1 is list
        mergeSub(l2,...,ln), otherwise
    }
*/


mergeSub([],C,C).
mergeSub([H|T],C,R):-
    is_list(H),
    merge(C,H,RM),
    mergeSub(T,RM,R).
mergeSub([H|T],C,R):-
    not(is_list(H)),
    mergeSub(T,C,R).


mainSub(L,R):-
    mergeSub(L,[],RMS),
    removeDoubles(RMS,RD),
    R = RD.
