--Find the customers of the bank who have an account but not a loan

(select customer_name
from depositor)
except
(select customer_name
from borrower);
