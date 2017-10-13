--Find all employees in the database who do not work for First Bank Corporation.

select employee_name from works
where company_name != 'First Bank Corporation'
