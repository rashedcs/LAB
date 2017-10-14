--Find the number of accidents in which cars belonging to a specific model were involved.

select count(*) as Total from car ca, participated pa 
where ca.licence=pa.licence and ca.model='BMW';
