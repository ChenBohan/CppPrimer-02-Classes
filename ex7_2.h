// Exercise 7.2: Add the combine and isbn members to the Sales_data
// class you wrote for the exercises in § 2.6.2 (p. 76).

#ifndef Ex7_2_H
#define Ex7_2_h

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
