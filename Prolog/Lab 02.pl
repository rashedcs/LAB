parent(raihan,safi).
parent(jui, safi).
male(raihan).
female(jui).

brother(X,Y):- male(X), parent(X,Z), parent(Y,Z).




Goal :
?- brother(raihan,jui).
 True
