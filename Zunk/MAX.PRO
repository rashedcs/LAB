predicates
	go.
	max(integer,integer,integer).
clauses
	go:-
	readint(X),readint(Y),
	max(X,Y,_).
	max(X,Y,X):- X>Y,!,
	max(X,Y,Y).
	
	
