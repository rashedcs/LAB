-- Creating branch table
create table branch
(
       branch_name varchar(30),
       branch_city varchar(30),
       assests     int,
       primary key(branch_name)
);


-- Creating account table
create table account 
(
	account_number int,
	branch_name    varchar(30),
	balance        int,
	primary key(account_number),
	foreign key(branch_name) references branch(branch_name)
);


-- Creating customer table
create table customer
(
  	customer_name   varchar(30),
	customer_street varchar(30),
	customer_city   varchar(30),
	primary key (customer_name)
);




-- Creating depositor table
create table depositer 
(
  	customer_name   varchar(30),
        account_number int,
	primary key (customer_name, account_number),
	foreign key (customer_name)  references customer (customer_name),
	foreign key (account_number) references account (account_number)
);


-- Creating loan table=
create table loan
(
   	loan_number int,
        branch_name varchar(30),
	amount int,
	primary key(loan_number),
	foreign key(branch_name) references branch(branch_name)
);





-- Creating borrower table
create table borrower 
(
	customer_name varchar(30),
	loan_number int,
	primary key(customer_name, loan_number)
      /*
        foreign key (customer_name) references customer (customer_name),
        foreign key (loan_number) references loan (loan_number)
     */
);


