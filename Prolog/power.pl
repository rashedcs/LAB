PREDICATES
power(Integer,Integer).

CLAUSES

power(1,1).
power(N,P):-P>1,
      N=P*P.
write(N)
