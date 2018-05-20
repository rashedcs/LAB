 factorial(0, 1).
 factorial(N, F) :- 
       M is N-1, 
       factorial(M, T), 
       F is N*T.



Goal :
?- factorial(5,F).
   120
