CREATE PROCEDURE delete_detail(@deleteId varchar(50))
AS
   DELETE FROM dbo.studentinfo
   WHERE sid = @deleteId