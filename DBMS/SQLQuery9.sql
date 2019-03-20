use sample;
select ename,sal*12 "annual sal",isnull(comm,0) from emp
where sal>isnull(comm,0) and job='SALESMAN'
order by sal,ename;