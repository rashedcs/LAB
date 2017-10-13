--Find the maximum enrollment, across all sections, in Autumn 2009.

select max(enrollment) from (select count(ID) as enrollment from section natural join takes
where semester='Autumn' and year=2009  group by course_id, sec_id)
