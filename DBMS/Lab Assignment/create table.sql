--
-- Table structure for table attendence
--

create table attendence
(
   at_id int  auto_increment,
   roll  int(6) not null,
   atten_mark int not null,
   primary key(at_id)
);



--
-- Table structure for table class_test
--

create table class_test
(
   id int auto_increment,
   roll int(6) not null,
   name varchar(55) not null,
   ct1 int(2) not null,
   ct2 int(2) not null,
   ct3 int(2) not null,
   primary key(id, roll)
);
