--Find the names of all customers who live on the same street and in the same city as "Smith" 


--One way of writing the query is as follows.
select F.customer_name
from customer F join customer S using(customer_street, customer_city)
where S.customer_name = 'Smith' ;


--Another way of writting the query is as follows
select F.customer_name
from customer F join customer S using(customer_street, customer_city)
where S.customer_street=F.customer_street and S.customer_name = 'Smith' ;
