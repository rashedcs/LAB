-- Fine the IDs and names of all students who have not taken any course offering before Spring 2009

select id, name from student except select id, name from student natural join takes
where year<2009;
