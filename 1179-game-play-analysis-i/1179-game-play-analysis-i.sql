# Write your MySQL query statement below
SELECT a.player_id, event_date as first_login
FROM Activity a JOIN (
    SELECT player_id, MIN(event_date) as min_date
    FROM Activity a
    GROUP BY player_id
) b ON a.player_id = b.player_id
WHERE a.event_date = b.min_date