Trace
predicates
	location(string,string)
	go
	chkstate(string)
clauses
	go:-
		writef("%-10  %5  \n","CITY","STATE"),
		fail.
	go:-
		location(City,State),
		not(chkstate(State)),
		writef("%-10  %5  \n",City,State),
		fail.
	go.
	
	chkstate("DC").
	location("Jackson","MS").
	location("Washington","DC").
	location("Raleigh","NC").
