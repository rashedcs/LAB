--. Find the company that has the smallest payroll.

select company_name from works group by company_name
having sum(salary) <= all(select sum(salary) from works group by company_name);
