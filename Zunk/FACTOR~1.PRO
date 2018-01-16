domains
X, Y, Z, R1, R2=integer
Input=string

predicates
xyz(X,Y,Z)
truthtable(Input)
go

clauses
xyz(0,0,0).
xyz(0,0,1).
xyz(0,1,0).
xyz(0,1,1).
xyz(1,0,0).
xyz(1,0,1).
xyz(1,1,0).
xyz(1,1,1).

go:-
clearwindow,
write("Enter the Truth Table:"),nl,
readln(Input),
truthtable(Input),

go.

truthtable("x and y and z"):-
write("x","y","z"," ","out"),nl,
xyz(X,Y,Z),
bitand(X,Y,R1),
bitand(R1,Z,R2),
write(X, Y, Z," ",R2),nl,
fail.

truthtable("x or y or z"):-
write("x","y","z"," ","out"),nl,
xyz(X,Y,Z),
bitor(X,Y,R1),
bitor(R1,Z,R2),
write(X, Y, Z," ",R2),nl,
fail.


truthtable("x and y or z"):-
write("x","y","z"," ","out"),nl,
xyz(X,Y,Z),
bitand(X,Y,R1),
bitor(R1,Z,R2),
write(X, Y, Z," ",R2),nl,
fail.

truthtable("x or y and z"):-
write("x","y","z"," ","out"),nl,
xyz(X,Y,Z),
bitand(X,Y,R1),
bitor(R1,Z,R2),
write(X, Y, Z," ",R2),nl,
fail.
goal
go.

