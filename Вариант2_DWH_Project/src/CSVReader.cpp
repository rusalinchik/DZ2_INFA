#include "CSVReader.h"
#include <fstream>
#include <sstream>

std::vector<Sale> CSVReader::loadSales(const std::string& file) {
    std::vector<Sale> data;
    std::ifstream f(file);
    std::string line;

    while (std::getline(f, line)) {
        std::stringstream ss(line);
        Sale s;
        std::string tmp;

        std::getline(ss, tmp, ','); s.sale_id = std::stoi(tmp);
        std::getline(ss, s.sale_date, ',');
        std::getline(ss, tmp, ','); s.product_id = std::stoi(tmp);
        std::getline(ss, tmp, ','); s.customer_id = std::stoi(tmp);
        std::getline(ss, tmp, ','); s.quantity = std::stoi(tmp);
        std::getline(ss, tmp, ','); s.amount = std::stod(tmp);

        data.push_back(s);
    }
    return data;
}
