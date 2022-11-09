SELECT title FROM movies WHERE year = 2010
JOIN ratings ON movies.id = ratings.movie_id
SELECT ratings.rating;



