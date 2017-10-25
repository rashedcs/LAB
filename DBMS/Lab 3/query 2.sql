--Find the names, street address, and cities of residence of all em-ployees who work for First Bank Corporation 
--and earn more than $2500



select * from employee
where employee_name 
in(select employee_name from works where company_name = 'First Bank Corporation' and salary > 2500);

