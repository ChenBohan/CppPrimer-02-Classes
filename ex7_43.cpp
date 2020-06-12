// Exercise 7.43: Assume we have a class named NoDefault that has a
// constructor that takes an int, but has no default constructor. Define a class
// C that has a member of type NoDefault. Define the default constructor for
// C.

#include <vector>

class NoDefault {
public:
    NoDefault(int i) {}
};

class C {
public:
    C() : def(0) {}
private:
    NoDefault def;
};

int main() {
    C c;
    std::vector<C> vec(10);
    return 0;
}

