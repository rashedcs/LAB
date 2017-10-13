--Find the IDs and titles of all student who were atught by an instructor named Einstein;
--Make sure that there are no duplicate in the result

select course.id, course.title from courser, instructor, teaches 
where course.id = teaches.course_id and instructor.id = teaches.instructor_id and instructor.name = 'Einstein' ;
