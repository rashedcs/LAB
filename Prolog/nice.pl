Predicates
position("Sojib",lecturer).
position('Sohel','Senior lecturer').

Clauses
find_position:-
	write('Whos position?'),nl,
        read(Input),nl,
	position(Input,Output),nl,
	write(Output).


?- find_positions.
