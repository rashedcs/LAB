--Find the names of all employees in this database who live in the same city as the company for which they work 

select E.employee_name from employee as E, works as W, company as C 
where E.employee_name=W.employee_name and E.city=C.city and W.company_name=C.company_name;
   
