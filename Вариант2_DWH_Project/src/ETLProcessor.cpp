#include "ETLProcessor.h"
#include "CSVReader.h"
#include "DateUtils.h"

void ETLProcessor::loadSales(Database& db) {
    auto sales = CSVReader::loadSales("data/sales.csv");

    for (const auto& s : sales) {
        std::string date = DateUtils::normalizeDate(s.sale_date);

        std::string sql =
            "INSERT INTO sales_fact VALUES (" +
            std::to_string(s.sale_id) + ", '" +
            date + "', " +
            std::to_string(s.product_id) + ", " +
            std::to_string(s.customer_id) + ", " +
            std::to_string(s.quantity) + ", " +
            std::to_string(s.amount) + ");";

        db.execute(sql);
    }
}
