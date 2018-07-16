loop(0).
loop(N) :-
    between(1, N, X),
    writeln(X),
    X >= N, !.
    loop(X).
    
    
    
loop(0,0).
loop(M,N) :-
    between(M, N, X),
    writeln(X),
    X >= N, !.
    loop(M,X).   
