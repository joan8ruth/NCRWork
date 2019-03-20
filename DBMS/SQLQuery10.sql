use sample;
select concat(ename,'-',job) as name_designation,floor(sal+(0.15*sal)) as increased_sal from emp;