start:-
  read_grade(X) ,
  evaluate_grade(X,R),
  write('Your CGPA is ') ,
  write(R) ,
  nl
  .

read_grade(X) :-
  write('please enter your CGPA: ') ,
  read(X),
  number(X)
  .

evaluate_grade( X , poor      ) :- X >= 0.0 , X < 2.0 .
evaluate_grade( X , good      ) :- X >= 2.0 , X < 3.0 .
evaluate_grade( X , excellent ) :- X >= 3.0 .
