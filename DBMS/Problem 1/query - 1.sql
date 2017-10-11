-- Query 1 : Find titles of courses in Computer Science department that have 3 credits

select title
from course
where dept name = "Computer Science "
and credits = 3
