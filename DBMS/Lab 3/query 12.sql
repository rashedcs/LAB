--. Give all managers of First Bank Corporation a 10-percent raise.

update works set salary = salary * 1.1
where employee_name in(select manager_name from manages) and company_name='First Bank Corporation';
