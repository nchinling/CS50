SELECT Column_Fname, Column_Lname, table_Department.Column_Dname
FROM Table_Employee
WHERE Table_Employee.Column_DeptNo = table_Department.Column_DeptNo


SELECT movies.title, ratings.rating
FROM movies, ratings
WHERE movies.year = 2010;


