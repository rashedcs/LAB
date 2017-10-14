create table person
(
   driver_id int,
   name varchar(30),
   address varchar(30),
   primary key(driver_id)
);



create table car
(
  licence varchar(30),
  model   varchar(30),
  year    numeric(4,0),
  primary key(licence)
);



create table accident
(
  report_number int,
  acc_date  date,
  location varchar(30),
  primary key(report_number)
);





create table owns
(
  driver_id int,
  licence  varchar(30),
  primary key(driver_id, licence)
);



create table participated
(
   driver_id int,
   licence   varchar(30),
   report_number int,
   damage_amount int,
   primary key(report_number, licence)
);
