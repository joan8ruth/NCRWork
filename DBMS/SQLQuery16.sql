use sample;
select deptno,count(*) from emp
group by deptno
having count(*)>3
order by deptno;