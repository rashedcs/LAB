--Find the names of all customers who live on the same street and in the same city as "Smith" 

select F.customer_name
from customer F join customer S using(customer_street, customer_city)
where S.customer_name = ’Smith’ ;
