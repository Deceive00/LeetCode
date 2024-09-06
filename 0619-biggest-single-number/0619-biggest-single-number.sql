SELECT COALESCE(
    (
    SELECT MAX(a.num)
    FROM (
        SELECT num
        FROM MyNumbers
        GROUP BY num
        HAVING COUNT(*) = 1
    ) a
    ), NULL) AS num;