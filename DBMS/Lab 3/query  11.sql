--Find the names of all employees in this database who live in the same city as the company for which they work 

select E.person_name from Employee as E, Works as W, Company as C 
where E.employee_name=W.employee_name and E.city=C.city and W.company_name=C.company_name;
