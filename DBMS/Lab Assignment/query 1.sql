--Find the total marks where total marks = sum of max two class test + attendence

select distinct class_test.roll, class_test.name, class_test.ct1, class_test.ct2, class_test.ct3, 
((ct1+ct2+ct3)-LEAST(ct1,ct2,ct3)) as 'Sum of Max Two',  attendence.atten_mark as 'Attendence Marks', 
((attendence.atten_mark)+((ct1+ct2+ct3)-(LEAST(ct1,ct2,ct3)))) as Total 
from class_test,attendence
order by class_test.roll asc;
