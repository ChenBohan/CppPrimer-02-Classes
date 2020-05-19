// Exercise 7.9: Add operations to read and print Person objects to the code
// you wrote for the exercises in § 7.1.2 (p. 260).

#ifndef EX7_9_H
#define EX7_9_H

#include <string>
#include <iostream>

struct Person {
    std::string name;
    std::string address;

public:
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