/*
decomposition(N, C) = 
{
    oneSolution(N,C), C < N
    oneSolution(N, C+1), C < N
}

decompostion(N-number, C-number, R-result list)
decomposition(i, i, o)
*/

decomposition(N, C, R) :-
    C < N,
    oneSolution(N, C, R).
decomposition(N, C, R) :- 
    C < N,
    NewC is C + 1,
    decomposition(N, NewC, R).

/*
 oneSolution (N, C) = 
 {
    [], N = 0
    C U oneSolution(N-C, C+1), otherwise
 } 

 oneSolution(N-number, C-Number, R-result list)
 oneSolution(i, i, o)
*/

oneSolution(0,_,[]).
oneSolution(N, C, [C|R]) :-
    N >= C,
    NewN is N - C,
    NewC is C + 1,
    oneSolution(NewN, NewC, R).

/*
    allSolutions(N-number, R-result list)
    allSolutions(i, o)
*/

allsolutions(N, R) :-
    findall(RPartial, decomposition(N, 1, RPartial), R).
