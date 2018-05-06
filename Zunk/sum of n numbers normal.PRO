predicates
	sum(integer,integer)
clauses
	sum(0,0).
	sum(N,R):-
		N1=N-1,
		sum(N1,R1),
		R=R1+N.
		
		
		
		
