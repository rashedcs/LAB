parent(X,Y) :- father(X,Y).
parent(X,Y) :- mother(X,Y).
grandparent(X,Z) :- parent(X,Y), parent(Y,Z).
ancestor(X,Z) :- parent(X,Z).
ancestor(X,Y) :- parent(X,Y), ancestor(Y,Z).
sibling(X,Y) :- mother(M,X), mother(M,Y), 
                father(F,X), father(F,Y), X \= Y.
cousin(X,Y) :- parent(U,X), parent(V,Y), sibling(U,V).

father(albert, jeffrey).
mother(alice, jeffrey).
father(albert, george).
mother(alice, george).
father(john, mary).
mother(sue, mary).
father(george, cindy).
mother(mary, cindy).
father(george, victor).
mother(mary, victor).



parent(raihan,safi).
parent(jui, safi).
male(raihan).
female(jui).

brother(X,Y):- male(X), parent(X,Z), parent(Y,Z).
sister(X,Y):- female(X), parent(X,Z), parent(Y,Z).





Goal :
?- brother(raihan,jui).
 True
 
 
 link:http://www.dailyfreecode.com/Code/prolog-find-relations-family-3025.aspx
