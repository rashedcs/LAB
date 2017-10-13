--Find all employees who earn more than the average salary of all employees of their company.
--The following solution assumes that all people work for at most one company.

select employee_name  from works T
where salary > (select avg(salary) from works S where T.company_name = S.company_name);
