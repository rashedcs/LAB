user("Rika","1234").

getinput(Name,Password):-
        readln(Name),
        readln(Password).

main:-
        getinput(Name,Password),
        write(Name),nl,
        write(Password),nl,
        user(Name,Password).




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
