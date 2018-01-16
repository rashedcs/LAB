domains
	list=integer*
predicates
	findsum(list)
	sum(list,integer)
clauses
   findsum(L):-
	sum(L,sum),
	write("\n Sum of Given List:",sum).
	sum([],0).
   sum([X|Tail],sum):-
	sum(Tail,Temp),
	sum=Temp +X.	