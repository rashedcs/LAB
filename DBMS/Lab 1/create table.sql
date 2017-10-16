create table classroom
(
    building varchar(20),
    room_number    varchar(7),
    capacity  numeric(4,0),
    primary key(building, room_number)
);


create table department 
(
    dept_name varchar(30),
    building varchar(30),
    budget int,
    primary key(dept_name)
);


create table course
(
    course_id varchar(20),
    title     varchar(30),
    dept_name varchar(30),
    credits   numeric(2,0),
    primary key(course_id)
);


create table instructor 
(
    id int not null,
    name varchar(30) not null,
    dept_name varchar(30),
    salary int,
    primary key(id)
);



create table teaches
(
	id int,
	course_id varchar(20),
	sec_id    int,
	semester  varchar(20),
        year     numeric(4,0),
        primary key(id, course_id, sec_id, semester, year)
);


/*
create table section   
(
    course_id   varchar(20),
    sec_id      varchar(20),
    semester    varchar(30),
    year        numeric(4,0),
    building    varchar(20),
    room_number int,
    time_slot_id varchar(5),
    primary key(course_id, sec_id, semester, year)
);

*/

create table section
(
	 course_id		varchar(8), 
         sec_id			varchar(8),
	 semester		varchar(6) check (semester in ('Fall', 'Winter', 'Spring', 'Summer')), 
	 year			numeric(4,0) check (year > 1701 and year < 2100), 
	 building		varchar(15),
	 room_number		varchar(7),
	 time_slot_id		varchar(4),
	 primary key (course_id, sec_id, semester, year),
	 foreign key (course_id) references course
		on delete cascade,
	 foreign key (building, room_number) references classroom
		on delete set null
);





create table student
(        ID	varchar(5), 
	 name	varchar(20) not null, 
	 dept_name varchar(20), 
	 tot_cred numeric(3,0) check (tot_cred >= 0),
	 primary key (ID),
	 foreign key (dept_name) references department on delete set null
);



create table takes
(
	s_id int,
	course_id varchar(20),
	sec_id    int,
	semester  varchar(20),
        year     numeric(4,0),
        grade    varchar(10)
);


/*
create table takes
(        ID			varchar(5), 
	 course_id		varchar(8),
	 sec_id			varchar(8), 
	 semester		varchar(6),
	 year			numeric(4,0),
	 grade		        varchar(2),
	 primary key (ID, course_id, sec_id, semester, year),
	 foreign key (course_id,sec_id, semester, year) references section
		on delete cascade,
	 foreign key (ID) references student
		on delete cascade
);
*/

create table advisor
(        s_ID			varchar(5),
	 i_ID			varchar(5),
	 primary key (s_ID),
	 foreign key (i_ID) references instructor (ID)
		on delete set null,
	 foreign key (s_ID) references student (ID)
		on delete cascade
);

create table time_slot
(        time_slot_id		varchar(4),
	 day			varchar(1),
	 start_hr		numeric(2) check (start_hr >= 0 and start_hr < 24),
	 start_min		numeric(2) check (start_min >= 0 and start_min < 60),
	 end_hr			numeric(2) check (end_hr >= 0 and end_hr < 24),
	 end_min		numeric(2) check (end_min >= 0 and end_min < 60),
	 primary key (time_slot_id, day, start_hr, start_min)
);

create table prereq
(
	 course_id		varchar(8), 
	 prereq_id		varchar(8),
	 primary key (course_id, prereq_id),
	 foreign key (course_id) references course
		on delete cascade,
	 foreign key (prereq_id) references course
);




