--For each department, find the maximum salary of instructor in that department.
--You may assume that every department has at least one instructor

select dept_name, max(salary) from instructor group by dept_name;   
