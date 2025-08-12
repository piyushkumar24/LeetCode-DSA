# Write your MySQL query statement below

Select W1.id from Weather W1 JOIN Weather W2 ON W1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY) where W1.temperature > W2.temperature;