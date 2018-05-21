%domains
  name =  string
  pass =  string

 
user(name, pass).
attemp(integer).
messege(integer).


user("Rita","1234").



getinput(Name,Password):-
        readln(Name),
        readln(Password).

 message(X) :-
        X=0,
        write("Login Failed\nPlease Try Again!\n").
    message(0).       

attemp(X):-
	getinput(Name,Password),
        %write(Password),nl,
        user(Name, Password),
        write("You logged", Name, "."), nl,
        user(Name,Password),
        Y is X-1,
        messege(Y),
        attemp(Y),
    attemp(0).


main:-
     write("You Try"),nl,
     attemp(3),
     write("You Unsuccessful"), nl.


     







  

go:-
    write("Enter user name and password\n"),
    readln(User),
    readln(Pass),
    login(User,Pass),
    write("Login sucessful\n").
go:-
    write("Login unsucessful\n"),
    go.
login(dharmik,123).
login(nihar,456).
