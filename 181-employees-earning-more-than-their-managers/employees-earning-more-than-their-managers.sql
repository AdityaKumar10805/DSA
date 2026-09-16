# Write your MySQL query statement below
SELECT a.name Employee FROM Employee a LEFT JOIN Employee b ON a.managerId=b.id WHERE a.salary>b.salary