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
