// Exercise 7.15: Add appropriate constructors to your Person class.

#ifndef EX7_15_H
#define EX7_15_H

#include <string>
#include <iostream>

struct Person {
    std::string name;
    std::string address;
public:
    Person() = default;
    Person(const std::string& n):name(n) {}
    Person(const std::string& n, const std::string& ad):name(n), address(ad) {}
    Person(std::istream &is) { read(is, *this); }
    std::string const& getName() const { return name; }
    std::string const& getAddress() const { return address; }
};

std::ostream& print(std::ostream &os, const Person& person) {
    return os << person.name << " " << person.address;
}

std::istream& read(std::istream &is, Person& person) {
    return is >> person.name >> person.address;
}

#endif