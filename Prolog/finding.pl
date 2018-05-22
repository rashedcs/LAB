student(mehedi,01).
student(baki,18).
student(fahim,24).
student(arafat,26).
student(hakkani,32).
student(rashed,35).
student(biswas,42).
student(masum,43).
student(nazmul,48).



attempt:-
  	read(Name),nl,
	student(Name,Roll),
	write(Name),nl,
	write(Roll),nl.



main:-
  attempt.
