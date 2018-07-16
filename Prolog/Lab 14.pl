fib(0, 0).
fib(1, 1).
fib(N,NF) :-
	N>1,
	A is N-1,
        B is N-2,
        fib(A,AF),fib(B,BF),
        NF is AF+BF.



?- fib(5,F). 
