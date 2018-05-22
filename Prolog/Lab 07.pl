user(mehedi,123).
user(baki,456).
user(masum,456).
user(hakkani,123).


getinput(User,Pass) :-
	read(User),nl,
	read(Pass),nl.


attempt(_) :-
	getinput(User,Pass),
	user(User,Pass),
	write("You are now logged on."),nl.

attempt(X) :-
	write("Wrong username or password"),nl,
	M = X-1,
	attempt(M).

attempt(0) :-
	write("Sorry, you are not permitted access.").	


main :-
	attempt(3).
























     


  
