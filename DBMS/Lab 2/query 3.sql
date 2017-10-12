--Find the names of all branches with customers who have an account
--in the bank and who live in “Harrison”.

select distinct branch name
from account natural join depositor natural join customer
where customer city = ’Harrison’

