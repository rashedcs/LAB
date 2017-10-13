--Find the company that has the most employees


select company_name from works
group by company_name
having count (distinct employee_name) >= all
(select count (distinct employee_name) from works group by company_name);
