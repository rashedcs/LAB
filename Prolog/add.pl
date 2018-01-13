sum(X,Y):-
  S is X+Y,
  write(S).




Using user input :

  sum:-
	write('Number 1 ?'),nl,
        read(Input1),nl,
	write('Number 2 ?'),nl,
        read(Input2),nl,
	Output is Input1*Input2,
	write(Output).



Another way :

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
