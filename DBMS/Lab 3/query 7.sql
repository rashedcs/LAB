--Find those companies whose employees earn a higher salary, on average than the average salary at First Bank Corporation.

select company_name from works
group by company_name
having avg(salary) > (select avg(salary) from works
                       where company_name = 'First Bank Corporation');
