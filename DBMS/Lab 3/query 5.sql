--Find all companies located in every city in which Small Bank Corporation is located.


--Simply way
select T.company_name from company T
where 
(select R.city from company R where R.company_name = T.company_name)
contains
(select S.city from company S where S.company_name="Small Bank Corporation");




--Standard way
select S.company_name from company S
where not exists 
(
  (select city from company where company_name = 'Small Bank Corporation')
  except
  (select city from company  T where S.company_name = T.company_name) 
);
