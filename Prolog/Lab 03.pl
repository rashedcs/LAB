loop(0).
loop(N):-
    write(N),nl,
    M is N-1,
    loop(M).
