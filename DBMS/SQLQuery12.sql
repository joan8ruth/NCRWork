use sample;
select min(sal) as minimum,max(sal) as maximum,job  from emp group by job;