# Write your MySQL query statement below
SElECT t1.id, 
CASE
    WHEN t1.p_id IS NULL THEN "Root"
    WHEN t1.id IN (
        SELECT DISTINCT t2.p_id FROM Tree t2
    ) THEN "Inner"
    ELSE "Leaf"
END
as type
FROM Tree t1

-- SELECT * FROM
-- Tree t1 WHERE t1.id IN (
--         SELECT DISTINCT t2.p_id FROM Tree t2
--     )