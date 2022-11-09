-- SELECT title FROM movies WHERE year = 2010;
-- JOIN ratings ON movies.id = ratings.movie_id
-- SELECT ratings.rating;


SELECT movies.title, ratings.rating
FROM movies, ratings
WHERE movies.year = 2010;


