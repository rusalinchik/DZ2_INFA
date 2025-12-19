SELECT p.category, SUM(s.amount)
FROM sales_fact s
JOIN products_dim p ON s.product_id = p.product_id
GROUP BY p.category;

SELECT c.region, COUNT(*)
FROM sales_fact s
JOIN customers_dim c ON s.customer_id = c.customer_id
GROUP BY c.region;

SELECT t.year, t.month, AVG(s.amount)
FROM sales_fact s
JOIN time_dim t ON s.sale_date = t.date
GROUP BY t.year, t.month;
