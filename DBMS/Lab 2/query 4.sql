--Find the names of all branches that have assests greate than those of at least one branch located in "Brooklyn"

select branch_name from branch where assests > some(select assests from branch where branch_city="Brooklyn");
