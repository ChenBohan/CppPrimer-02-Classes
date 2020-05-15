// Exercise 7.5: Provide operations in your Person class to return the name
// and address. Should these functions be const ? Explain your choice.

#ifndef Ex7_5_H
#define Ex7_5_H

#include <string>

class Person {
    std::string name;
    std::string address;
public:
    std::string getName() const { return name; };
    std::string getAddress() const { return address; };
};

#endif