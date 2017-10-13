

create table employee
(
    employee_name varchar(30),
    street        varchar(30),
    city          varchar(30),
    primary key (employee_name)
);

create table works
(
    employee_name varchar(30),
    company_name  varchar(30),
    salary        numeric(6,0),
    primary key(employee_name)
);


create table company
(
    company_name varchar(30),
    city         varchar(30),
    primary key(company_name)
);


create table manages
(
    employee_name varchar(30),
    manager_name varchar(30),
    primary key(employee_name)
);
 
