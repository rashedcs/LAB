--Delete the Mazda belonging to “John Smith”.

delete car where model = 'MENZ' and licence in
(select licence from person p, owns o where p.name ='Nazmul Hossain' and p.driver_id = o.driver_id);
