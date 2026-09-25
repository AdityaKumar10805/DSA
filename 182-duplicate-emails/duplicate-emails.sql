# Write your MySQL query statement below
SELECT email Email FROM Person GROUP BY email having count(email)>1