use sample;
select ename,sal+isnull(comm,0) as renumeration from emp;