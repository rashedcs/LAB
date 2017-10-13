--Find the enrollment of each section that was offered in Autumn 2009.

select course_id, sec_id, count(ID)  from section natural join takes
where semester='Autumn' and year=2009  group by course_id, sec_id;
