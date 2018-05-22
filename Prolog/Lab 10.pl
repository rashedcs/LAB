input(X) :-
  %write('Enter CGPA : '),
  read(X),nl.
  

output(X , poor      ) :- X >= 0.0 , X < 2.0 .
output(X , good      ) :- X >= 2.0 , X < 3.0 .
output(X , excellent ) :- X >= 3.0 , X < 4.00.
output(X , outstanding) :- X==4.00.


main:-
  input(X) ,
  output(X,R),
  write('Your CGPA is ') ,
  write(R),nl.


