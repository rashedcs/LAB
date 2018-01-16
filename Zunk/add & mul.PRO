domains
	product,sum=integer
predicates
	add(Sum,Sum,Sum)
	multiply(Product,Product,Product)
clauses
	add(X,Y,Sum):- Sum=X+Y.
	multiply(X,Y,Product):- Product=X*Y.