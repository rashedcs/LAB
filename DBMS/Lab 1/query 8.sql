-- Find the names of all students who have taken at least one Comp. Sci. course; make sure
--there are no duplicate name in the result.

select name from student natural join takes natural join course
where course.dept = 'Computer Science';
     
