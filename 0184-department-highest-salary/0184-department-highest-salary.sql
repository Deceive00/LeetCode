# Write your MySQL query statement below
-- SELECT d.name as Department, e.name as Employee, Salary
-- FROM Employee e JOIN Department d ON e.departmentId = d.id
-- GROUP BY d.id
-- HAVING salary = MAX(salary)
SELECT a.Department, e.name as Employee, e.Salary
FROM (
    SELECT d.id as departmentId, d.name as Department, MAX(Salary) as MaxSalary
    FROM Department d JOIN Employee e ON d.id = e.departmentId
    GROUP BY d.id
) a JOIN Employee e ON a.departmentId = e.departmentId
WHERE e.Salary = a.MaxSalary
