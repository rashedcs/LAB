sum(0,0).
sum(N,R) :-
  N > 0 ,
  M is N-1 ,
  sum(M, T) ,
  R is T+N .
  
  
  
Goal :
?- sum(5,R).
   15