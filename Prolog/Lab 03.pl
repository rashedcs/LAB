loop(0).
loop(N):-
    write(N),nl,
    M is N-1,
    N>0,
    loop(M).
