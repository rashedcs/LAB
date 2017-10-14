--Find the total number of people who owned cars that were involved in accidents in the year 2008.

  select count(distinct o.driver_id) as People from owns o, participated p, accident a 
  where a.acc_date like '%12' and o.licence=p.licence and p.report_number=a.report_number;
