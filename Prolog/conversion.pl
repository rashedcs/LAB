program :- 
dec2bin(0,[0]).
dec2bin(1,[1]).
dec2bin(N,L) :- 
    N > 1,
    X is N mod 2,
    Y is N // 2,  
    dec2bin(Y,L1), 
    append(L1, [X], L).
