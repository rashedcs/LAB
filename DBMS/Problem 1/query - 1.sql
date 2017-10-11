-- Query 1 : Find titles of courses in Computer Science department that have 3 credits

select title
from course
where dept_name = "Computer Science "
and credits = 3;
