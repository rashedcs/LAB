--Find the customers of the bank who have an account but not a loan.

select distinct customer_name from borrower where not in(select customer_name from depositor); 
