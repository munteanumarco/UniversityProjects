bubblesort(List,SortedList):-
    swap(List,RList), ! ,
    bubblesort(RList, SortedList) .
bubblesort(List,List).

swap([X,Y|Rest],[Y,X|Rest]):-
    X > Y, ! .
swap([Z|Rest],[Z|Rest1]):-
    swap(Rest,Rest1).


/*
removeDoubles(l1,..,ln) = {
    [], n = 0
    l1 U removeDoubles(l2,...,ln), l1 != l2
    removeDoubles(l2,...,ln), otherwise
}
*/

removeDoubles([],[]).
removeDoubles([H],[H]).
removeDoubles([H1,H2|T],[H1|R]):-
    H1 =\= H2,
    removeDoubles([H2|T], R).
removeDoubles([H1,H2|T], R):-
    H1 =:= H2,
    removeDoubles([H2|T], R).

main([],[]).
main(L,R):-
    bubblesort(L,RL),
    removeDoubles(RL,RRL),
    R = RRL.

/*
    doSublist(l1,...,ln) = {
        [], n = 0
        main(l1) U doSublist(l2,...,ln), l1 is list
        l1 U doSublist(l2,...,ln), otherwise
    }
*/

doSublist([],[]).
doSublist([H|T], [H|R]):-
    not(is_list(H)),
    doSublist(T,R).
doSublist([H|T], [RM|R]):-
    is_list(H),
    main(H,RM),
    doSublist(T, R).


