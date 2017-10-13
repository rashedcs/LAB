--Find all employees in the database who earn more than each employee of Small Bank Corporation.

select employee_name from works
where salary > all(select salary from works where company_name = "Small Bank Corporation");
