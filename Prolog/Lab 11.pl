%First Program :

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




%Second Program :

student(symbol,symbol, integer)
       choice(integer)


%clauses
    	assert(student("baki","pabna",150118)).
        assert(student("rashed","sirajganj",150135)).
        assert(student("nazmul","rajshahi",150148)).


    choice(1):-
        readint(name),nl,
        student(name,zilla,num),
        write(name), write(" "), write(zilla), write(" "), write(num),
        fail.

    choice(2):-
        readint(num),nl,
        student(name,zilla,num),
        write(name), write(" "), write(zilla), write(" "), write(num),
        fail.

    choice(0) :- !.


    goal:-
       repeat,
        write("1. Search by name"),nl,
        write("2. Search by num"),nl,
        write("0. Exit"),nl,
       %write("Enter your choice : "),nl,
        read(CH),
        choice(CH). 



