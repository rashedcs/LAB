parent(yakub, yusuf).
parent(yakub, levi).
parent(yakub, beniamin).
parent(yakub, yahuda).
parent(yakub, benti).

parent(yusuf, abraham).
parent(lebi, levi).


parent(rahela, yusuf).
parent(rahela, beniamin).
parent(lia, levi).
parent(lia, yahuda).

male(yakub).
male(yusuf).
male(levi).
mle(yahuda).
male(beniamin).

female(rahela).
female(lia).
female(benti).



brother(X,Y):- male(X), parent(Z,X), parent(Z,Y).
sister(X,Y):-  female(X), parent(Z,X), parent(Z,Y).


father(X,Y) :- male(X), parent(X,Y).
mother(X,Y) :- female(X), mother(X,Y).

grandpa(X,Z) :- male(X), parent(X,Y), parent(Y,Z).
grandma(X,Z) :- female(X), parent(X,Y), parent(Y,Z).



?- brother(X,levi),!.
X = yusuf.


?- sister(Y,levi).
Y = benti 

