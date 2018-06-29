%domains
name, color, company = symbol
price =integer

%predicates
car(name,color,company,price)


%clauses
car(toyota,tata,black,125000).
car(bmw, maruti,white,225000).
car(swift,maruti,black,505000).
car(van,maruti,red,455000).
car(fiat,fiat,gray,325000).



Goals:
?- car(bmw,_,_,_).
true.

?- car(bmw,_,_,_).
true.
