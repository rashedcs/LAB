--Find the names of all employees who live in the same city and on the same street as do their managers.

select E1.person_name from Employee as E1, employee as E2, manages as M
Where E1.person_name=M.person_name and E2.person_name=M.manager_name and E1.stree=E2.street and E1.city=E2.city;

