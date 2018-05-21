loop(0).
loop(N) :-
    between(1, N, X),
    writeln(X),
    X >= N, !.
    loop(X).
    
    
    
