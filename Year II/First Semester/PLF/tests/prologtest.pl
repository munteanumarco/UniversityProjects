/*
    merge(l1,l2,...,ln,c1,....,cm) = {
        [], n = 0 and m = 0
        l1 U merge(l2,...,ln,c1,...,cm), n != 0, m != 0, l1 <= c1
        c1 U merge(l1,...,ln,c2,...,cm), n != 0, m != 0, l1 > c1
        l1 U merge(l2,...,ln), m = 0 , n != 0
        c1 U merge(c2,...,cm), n = 0 , m != 0 
    }

    merge(L-list1, C-list2, R -result list)
    merge(i,i,o)
*/

/*
    removeDuplicates(l1,l2,...,ln) = {
        [], n = 0
        [l1], n = 1
        l1 U removeDuplicates(l2,...,ln), l1 != l2
        removeDuplicates(l2,...,ln), l1 == l2
    }

    removeDuplicates(L-list, R - result list)
    removeDuplicates(i,o)
*/
/*
l1a 8 
l1b 8
*/

merge([],[],[]):-!.
merge([H1|T1],[H2|T2], [H1|R]):-
    H1 =< H2,
    merge(T1,[H2|T2],R).
merge([H1|T1],[H2|T2], [H2|R]):-
    H1 > H2,
    merge([H1|T1],T2,R).
merge([H1|T1],[], [H1|R]):-
    merge(T1,[],R).
merge([],[H2|T2], [H2|R]):-
    merge([],T2,R).


removeDuplicates([],[]).
removeDuplicates([H],[H]).
removeDuplicates([H1,H2|T], [H1|R]):-
    H1 =\= H2,
    removeDuplicates([H2|T], R).
removeDuplicates([H1,H2|T], R):-
    H1 =:= H2,
    removeDuplicates([H2|T],R).
 

main(L1,L2,R):-
    merge(L1,L2,RM),
    removeDuplicates(RM,R).

