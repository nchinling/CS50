SELECT title FROM movies WHERE year = 2010, ratings.rating
FROM movies
JOIN ratings
on movies.id = ratings.movie_id

SELECT tablename1.colunmname1, tablename2.colunmname2
FROM tablename1
JOIN tablename2
ON tablename1.colunmname1= tablename2.colunmname1
[ORDER BY expression [ ASC | DESC ]];




In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
Movies that do not have ratings should not be included in the result.