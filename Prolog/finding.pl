user(mehedi,01).
user(baki,18).
user(masum,43).
user(hakkani,32).
user(rashed,35).
user(fahim,24).
user(arafat,26).



attempt:-
  	read(Name),nl,
	user(Name,Password),
	write(Name),nl,
	write(Password),nl.



main:-
  attempt.
