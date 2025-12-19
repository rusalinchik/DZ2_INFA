#include "DateUtils.h"
#include <sstream>
#include <iomanip>

std::string DateUtils::normalizeDate(const std::string& date) {
    std::tm tm{};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");

    std::ostringstream out;
    out << std::put_time(&tm, "%Y-%m-%d");
    return out.str();
}
