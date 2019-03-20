use sample;
select job,avg(sal) as average, sum(sal+isnull(comm,0)) as renumeration from emp group by job;