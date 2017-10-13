--Find the lowest, across all departments of the per-department maximum salary computed by the preceding query.

selct min(maximum_salary) from (select dept_name, max(salary) as maximum_salary from instructor)
group by dept_name;
