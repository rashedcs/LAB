user(mehedi,123).
user(baki,456).
user(masum,456).
user(hakkani,123).

getinput(Name,Password) :-
	read(Name),nl,
	read(Password),nl,
	user(Name,Password).

attempt(_) :-
	getinput(_,_),
	write("You are now logged on."),nl.

attempt(N) :-
	write("Sorry, you are not permitted access."),nl,
	write("Please try again."),nl,
	getinput(_,_),
	write("You are now logged on."),nl,
	M is N-1.
attempt(M).

attempt(0) :-
	write("Sorry, you are not permitted access.").


main:-
  attempt(5).




/* Using repeat predicate */
user(mehedi,123).
user(baki,456).
user(masum,456).
user(hakkani,123).

getinput(Name,Password) :-
	read(Name),nl,
	read(Password),nl,
	user(Name,Password).

attempt :-
	getinput(_,_),
	write("You are now logged on."),nl.

attempt :-
    repeat,
	write("Sorry, you are not permitted access."),nl,
	write("Please try again."),nl,
	getinput(_,_),
	write("You are now logged on."),nl.





%Daught : https://ideone.com/lEZmXy  
