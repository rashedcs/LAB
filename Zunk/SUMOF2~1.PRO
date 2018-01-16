predicates
	start	
	sum
clauses
	start:- sum,nl.
	sum:-
		write("Give X="),readreal(X),
		write("Give Y="),readreal(Y),
		S=X+Y,
		write("Sum is= "),write(S).
