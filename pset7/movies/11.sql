SELECT title FROM movies JOIN stars ON movies.id = stars.movie_id JOIN ratings ON stars.movie_id = ratings.movie_id JOIN people ON people.id = stars.person_id WHERE people.name = "Chadwick Boseman" ORDER BY ratings.rating LIMIT 5;