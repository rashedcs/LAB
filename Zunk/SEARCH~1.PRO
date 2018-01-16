domains
	list=integer*

predicates

	findnum(integer,list)

clauses

	findnum(X,[]):-
		write("\n Number is not found").

	findnum(X,[X]Tail):-
		write("\n Number is found").

	findnum(X,[Y]Tail):-
		findnum(X,Tail).