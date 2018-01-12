domains
  Item =  int,
  Price = int,

predicates
  askprice(Item,Price)

clauses
askprice(Item,Price):-
    write("Input first num : "),
    readint(Item),
    write("Input second num : "),
    readint(Price).

