#ifndef CELL_H
#define CELL_H

#include <iostream>
#include "Date.h"
#include <string>
#include <sstream>

enum class Color { Red = 1, Green, Blue}; 


class Cell {
public:
    Cell() = default;
    virtual ~Cell() = default;
    void setColor(Color color) { m_color = color;}
    Color getColor() const { return m_color; }
    virtual std::string getStringValue() = 0;
private:
    Color m_color;
};


class IntCell : public Cell {
public:
    IntCell(int new_value, Color color) : value{new_value} { setColor(color); }
    int getValue() const { return value; }
    void setValue(int new_value) { value = new_value; }
    std::string getStringValue() override { return std::to_string(value); }
private:
    int value;    
};


class DoubleCell : public Cell {
public:
    DoubleCell(double new_value, Color color) : value{new_value} { setColor(color); }
    double getValue() { return value; } 
    void setValue(double new_value) { value = new_value; }
    std::string getStringValue() override { return std::to_string(value); }
private:
    double value;
};


class StringCell : public Cell {
public:
    StringCell(const std::string& new_value, Color color) : value{new_value} { setColor(color); }
    std::string getValue() const { return value; }
    void setValue(const std::string& new_value) { value = new_value; }
    std::string getStringValue() override { return value; }
private:
    std::string value;
};


class DateCell : public Cell {
public:
    DateCell(const Date& new_value, Color color) : value{new_value} { setColor(color); }
    Date getValue() const { return value; }
    void setValue(Date new_value) { value = new_value; } 
    std::string getStringValue() override { return value.getDate(); }             //avelacnel??
private:
    Date value;
};

#endif //CELL_H