#include <iostream>
#include "Date.h"

Date::Date(const std::string &date_string) {
    std::regex date_regex("(\\d{4})-(\\d{2})-(\\d{2})");

    if (!std::regex_match(date_string, date_regex)) {
    throw std::invalid_argument("Invalid date format");
    }

    date = date_string;
}

void Date::setDate(const std::string& new_date) {
    date = new_date;
}
std::string Date::getDate() const {
    return date;
}