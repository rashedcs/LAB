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



create table teaches
(
	id int,
	course_id varchar(20),
	sec_id    int,
	semester  varchar(20),
        year     numeric(4,0),
        primary key(id, course_id, sec_id, semester, year)
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

