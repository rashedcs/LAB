-- inserting branch table with  values
insert into branch values
	('Brighton', 'Brooklyn', 7100000),
	('Downtown', 'Brooklyn', 9000000),
	('Mianus',   'Horseneck', 400000),
	('North Town', 'Rye',    3700000),
	('Perryridge', 'Horseneck', 1700000),
        ('Pownal', 'Bennington', 300000),
        ('Redwood', 'Palo Alto', 2100000),
        ('Round Hill', 'Horseneck', 8000000);



-- Inserting customer table with values
insert into customer values
	('Adams', 'Spring', 'Pittsfield'),
	('Brooks','Senator', 'Brooklyn'),
	('Curry', 'North',   'Rye'),
	('Glenn', 'Sand Hill', 'Woodside'),
	('Green', 'Walnut', 'Stamford'),
	('Hayes', 'Main', 'Harrison'),
	('Johnson', 'Alma', 'Palo Alto'),
	('Jones', 'Main', 'Harrison'),
	('Lindsay', 'Park', 'Pittsfield'),
	('Smith', 'North', 'Rye'),
	('Turner', 'Putnam', 'Stamford'),
	('Williams', 'Nassau', 'Princeton');
  
  
  
  
  -- Inserting loan table with values
insert into loan values
	(11, 'Round Hill', 900),
        (14, 'Downtown',   1500),
	(15, 'Perryridge', 1500),
	(16, 'Perryridge', 900),
	(17, 'Downtown',  1000),
	(23, 'Redwood',   2000),
	(93, 'Mianus',    500);
	
	
	
	
	
-- Inserting depositor table with values
 insert into  depositer  values
	('Hayes',   102),
	('Johnson', 101),	
	('Johnson', 201),
	('Jones',   217),	
	('Lindsay', 222),
	('Smith',   215),
	('Turner',  305);
  




  


-- Inserting borrower table with values
insert into borrower values
    ('Smith', 11),
    ('Jackson',14),
    ('Hayes', 15),
    ('Adams', 16),
    ('Jones',  17),
    ('Smith', 23),
    ('Curry', 93);



