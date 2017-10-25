--Find the names of all employees who live in the same city and on the same street as do their managers.

select E1.employee_name from employee as E1, employee as E2, manages as M
Where E1.employee_name=M.employee_name and E2.employee_name=M.manager_name and E1.street=E2.street and E1.city=E2.city;


