domains
	a,b=integer
predicates
	add(a, b)
 
clauses
	add:-
    write("Input first num : "),
    readint(X),
    write("Input second num : "),
    readint(Y),
    
    sum(X,Y):-
    Z=X+Y,
    write("Output=",Z).
