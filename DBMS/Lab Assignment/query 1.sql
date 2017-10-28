--Find the total marks where total = sum of max class test + attendence

SELECT DISTINCT class_test.roll,class_test.name,class_test.ct1,class_test.ct2,class_test.ct3, 
((ct1+ct2+ct3)-LEAST(ct1,ct2,ct3)) as 'Sum of Max Two',  attendence.atten_mark as 'Attendence Marks', 
((attendence.atten_mark)+((ct1+ct2+ct3)-(LEAST(ct1,ct2,ct3)))) as Total 
FROM class_test,attendence
ORDER BY class_test.roll ASC;
