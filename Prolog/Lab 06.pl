sum(0,0).
sum(N,R) :-
  N > 0 ,
  M is N-1 ,
  sum(M, T) ,
  R is N+T .
  
  
  
Goal :
?- sum(5,R).
   15
   
   
Sum Range : M to N.

sumFrom(X ,Y, S) :- X>Y, !, write('Start should not be greater than End').
sumFrom(X ,Y, S) :- X=Y, S=X.
sumFrom(X ,Y, S) :- 
        Next is X+1,
        sumFrom(Next, Y, Sum1),
        S is Sum1+X.   

?- sumForm(5,10,S).
Correct to: "sumFrom(5,10,S)"? yes
S = 45 



