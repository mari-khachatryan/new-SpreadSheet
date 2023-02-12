#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iterator>
#include <string>
#include <regex>

class Date {
public:
    Date() = default;
    virtual ~Date() = default;
    Date(const std::string &date_string);

    void setDate(const std::string& new_date);
    std::string getDate() const;

private:
    std::string date;
};

#endif //DATE_H