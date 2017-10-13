--Give all managers of First Bank Corporation a 10-percent raise unless the salary becomes greater than $100,000; 
--in such cases, give only a 3-percentraise.


--Simply way :
update works T set T.salary = T.salary * 1.03
where T.employee_name in (select manager_name from manages) 
and T.salary * 1.1 > 100000
and T.company_name = 'First Bank Corporation';


update works T
set T.salary = T.salary * 1.1
where T.employee_name in (select manager_name from manages)
and T.salary * 1.1 <= 100000
and T.company_name = 'First Bank Corporation' ;




--Another way :
update works T set T.salary = T.salary ∗ (case when (T.salary ∗ 1.1 > 100000) then 1.03  else 1.1 )
where T.employee-name in (select manager_name from manages) and T.company_name = 'First Bank Corporation';

