#pragma once
#include <string>

struct Sale {
    int sale_id;
    std::string sale_date;
    int product_id;
    int customer_id;
    int quantity;
    double amount;
};

struct Product {
    int product_id;
    std::string product_name;
    std::string category;
    double price;
};

struct Customer {
    int customer_id;
    std::string customer_name;
    std::string region;
};
