-- SELECT Column_Fname, Column_Lname, table_Department.Column_Dname
-- FROM Table_Employee
-- WHERE Table_Employee.Column_DeptNo = table_Department.Column_DeptNo


-- SELECT movies.title, ratings.rating
-- FROM movies, ratings
-- WHERE movies.year = 2010;

SELECT title, rating FROM movies, ratings
WHERE movies.id = ratings.movie_id and movies.year = 2010
ORDER BY rating DESC, title

-- SELECT movies.title, ratings.rating FROM movies
-- JOIN ratings ON movies.id = ratings.movie_id
-- WHERE year = 2010
-- ORDER BY rating DESC, title

-- In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
-- Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
-- Movies that do not have ratings should not be included in the result.
