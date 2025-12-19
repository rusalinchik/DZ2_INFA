CREATE TABLE products_dim (
    product_id INT PRIMARY KEY,
    product_name TEXT,
    category TEXT,
    price DOUBLE PRECISION
);

CREATE TABLE customers_dim (
    customer_id INT PRIMARY KEY,
    customer_name TEXT,
    region TEXT
);

CREATE TABLE time_dim (
    time_id SERIAL PRIMARY KEY,
    date DATE UNIQUE,
    year INT,
    quarter INT,
    month INT,
    day INT,
    day_of_week TEXT
);

CREATE TABLE sales_fact (
    sale_id INT PRIMARY KEY,
    sale_date DATE,
    product_id INT REFERENCES products_dim(product_id),
    customer_id INT REFERENCES customers_dim(customer_id),
    quantity INT,
    amount DOUBLE PRECISION
);
