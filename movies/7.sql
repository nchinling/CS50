-- SELECT title FROM movies WHERE year = 2010;
-- JOIN ratings ON movies.id = ratings.movie_id
-- SELECT ratings.rating;


SELECT t1.title, t2.rating
FROM movies t1, ratings t2
WHERE t1.year = 2010


