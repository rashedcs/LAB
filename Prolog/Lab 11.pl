
       student(symbol,symbol, integer)
       choice(integer)


%clauses
    	assert(student("baki","pabna",150118)).
        assert(student("rashed","sirajganj",150135)).
        assert(student("nazmul","rajshahi",150148)).


    choice(1):-
        read(name),nl,
        student(name,zilla,num),
        write(name),
        write(" "), 
        write(zilla), 
        write(" "), 
        write(num),
        fail.

    choice(2):-
        read(num),nl,
        student(name,zilla,num),
        write(num), write(" "), 
        write(zilla), 
        write(" "),
         write(name),
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

