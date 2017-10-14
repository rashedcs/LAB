create table member
(
  member_number int,
  name  varchar(30),
  age  int,
  primary key(member_number)
);



create table book
(
  isbn varchar(30),
  title varchar(30),
  author varchar(30),
  publisher varchar(30),
  primary key(isbn)
);



create table borrowed
(
  member_number int,
  isbn   varchar(30),
  date   date,
  primary key(member_number, isbn)
);
