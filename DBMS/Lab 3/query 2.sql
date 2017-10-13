--Find the names, street address, and cities of residence of all em-ployees who work for First Bank Corporation 
--and earn more than $10,000.



select * from employee
where employee name 
in(select employee name from works where company name = ’First Bank Corporation’ and salary > 10000)

