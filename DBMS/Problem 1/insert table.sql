insert into department(dept_name, building, budget)
	   values("Biology", "Watson", 90000);
insert into department(dept_name, building, budget)
	   values("Computer Science", "Taylor", 100000);
insert into department(dept_name, building, budget)
	   values("Electronics Engineering", "Taylor", 85000);
insert into department(dept_name, building, budget)
	   values("Finance", "Painter", 120000);
insert into department(dept_name, building, budget)
	   values("History", "Painter", 50000);
insert into department(dept_name, building, budget)
	   values("Music", "Packard", 80000);
insert into department(dept_name, building, budget)
	   values("Physics", "Watson", 70000);





insert into course(course_id, title, dept_name, credits)
      values("BIO-101", "Intro to Biology","Biology", 4);
insert into course(course_id, title, dept_name, credits)
      values("BIO-301", "Genetics","Biology", 4);
insert into course(course_id, title, dept_name, credits)
      values("CS-101", "Intro to Computer","Computer Science", 4);
insert into course(course_id, title, dept_name, credits)
      values("CS-190", "Game Design","Computer Science", 4);
insert into course(course_id, title, dept_name, credits)
      values("EE-101", "Digital Syste,","Electronics Engineering", 3);
insert into course(course_id, title, dept_name, credits)
      values("FIN-101", "Investment Banking","Finance", 3);
insert into course(course_id, title, dept_name, credits)
      values("HIS-351", "World History","History", 3);
 insert into course(course_id, title, dept_name, credits)
      values("MU-199", "Music Video Production","Music", 3);
insert into course(course_id, title, dept_name, credits)
      values("PHY-101", "Physical Principle","Physics", 4);
insert into course(course_id, title, dept_name, credits)
    values("CS-319", "Image Processing","Computer Science", 3);  
      
      
      
      
insert into instructor(id, name, dept_name, salary)
	   values(10101, "Srinivasan", "Computer Science", 65000);
insert into instructor(id, name, dept_name, salary) 
	   values(12121, "Wu", "Finance", 90000);
insert into instructor(id, name, dept_name, salary) 
	   values(15151, "Mozart", "Music", 40000);
insert into instructor(id, name, dept_name, salary) 
	   values(22222, "Einstein", "Physics", 95000);
insert into instructor(id, name, dept_name, salary) 
	   values(32343, "El Said", "History", 60000);
insert into instructor(id, name, dept_name, salary) 
	   values(45565, "Katz", "Computer Science", 75000);
insert into instructor(id, name, dept_name, salary) 
	   values(58583, "Califieri", "History", 62000);
insert into instructor(id, name, dept_name, salary) 
	   values(65653, "Singh", "Finance", 80000);
insert into instructor(id, name, dept_name, salary) 
	   values(76766, "Crick", "Biology", 72000);
      
      


insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("BIO-101", 1, "Summer", 2009, "Painter", 514, "B");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("BIO-301", 1, "Summer", 2010, "Painter", 514, "A");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("CS-101", 1, "Fall", 2009, "Packard", 101, "H");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("CS-101", 1, "Spring", 2010, "Packard", 101, "F");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("CS-190", 1, "Spring", 2009, "Taylor", 3128, "E");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("CS-190", 2, "Spring", 2009, "Taylor", 3128, "A");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("EE-181", 1, "Spring", 2009, "Taylor", 3128, "C");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("FIN-201", 1, "Spring", 2010, "Packard", 101, "B");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("HIS-351", 1, "Spring", 2010, "Painter", 514, "C");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("MU-199", 1, "Spring", 2010, "Packard", 101, "D");
insert into section(course_id, sec_id, semester, year, building, room_number, time_slot_id)
	values("PHY-101", 1, "Fall", 2009, "Watson", 100, "A");
	
	
	
	
insert into teaches(id, course_id, sec_id, semester, year)
	values(10101, "CS-101", 1, "Fall", 2009);
insert into teaches(id, course_id, sec_id, semester, year)
	values(10101, "CS-315", 1, "Spring", 2010);
insert into teaches(id, course_id, sec_id, semester, year)
	values(12121, "FIN-201", 1, "Spring", 2010);
insert into teaches(id, course_id, sec_id, semester, year)
	values(15151, "MU-199", 1, "Spring", 2010);
insert into teaches(id, course_id, sec_id, semester, year)
	values(22222, "PHY-101", 1, "Fall", 2009);
insert into teaches(id, course_id, sec_id, semester, year)
	values(32343, "HIS-351", 1, "Spring", 2010);
insert into teaches(id, course_id, sec_id, semester, year)
	values(76766, "BIO-101", 1, "Summer", 2009);
insert into teaches(id, course_id, sec_id, semester, year)
	values(76766, "BIO-101", 1, "Summer", 2010);
insert into teaches(id, course_id, sec_id, semester, year)
	values(98345, "EE-181", 1, "Spring", 2009);
	
	
	





