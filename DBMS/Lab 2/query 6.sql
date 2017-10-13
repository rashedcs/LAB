
--Find the names of all branches that have greater assets than those of at least one branches located in Brooklyn.

select branch_name from branch
where assets > all (select assets from branch where branch_city='Brooklyn');
