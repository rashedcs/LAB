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
