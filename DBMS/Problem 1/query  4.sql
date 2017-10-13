--Query : Find all instructors earning the highest salary (there may be more
than one with the same salary).

select ID, name from instructor where salary = (select max(salary) from instructor);
