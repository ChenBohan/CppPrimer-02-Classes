# CppPrimer-02-Classes
Solutions for Chapter 7.Classes exercises of C++ Primer 5th.

### Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p.76).

Any direct use of a member of the class is assumed to be an implicit reference through `this` .

```cpp
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

### Exercise 7.9: Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).

```cpp
std::ostream& print(std::ostream &os, const Person& person) {
    return os << person.name << " " << person.address;
}

std::istream& read(std::istream &is, Person& person) {
    return is >> person.name >> person.address;
}
```

### Exercise 7.11: Add constructors to your Sales_data class and write a program to use each of the constructors.

```cpp
// if we want the default behavior, we can ask the compiler
// to generate the constructor for us by writing = default after the parameter list.
Sales_data() = default;
// When a member is omitted from the constructor initializer list, it is implicitly initialized
// using the same process as is used by the synthesized default constructor, which is equivalent to
// Sales_data(const std::string &s):
//            bookNo(s), units_sold(0), revenue(0){ }
Sales_data(const std::string& s): bookNo(s) {}
Sales_data(const std::string& s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) {}
Sales_data(std::istream& is);
```
### Exercise 7.13: Rewrite the program from page 255 to use the istream constructor.

```cpp
std::istream &is = std::cin;
while (is) {
    Sales_data trans(is);
    ...
```

### Exercise 7.17: What, if any, are the differences between using class or struct?

- The only difference between using class and using struct to define a class is the default access level. (class : private, struct : public)

### Exercise 7.18: What is encapsulation? Why is it useful?

- encapsulation
    - encapsulation is the separation of implementation from interface. It hides the implementation details of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class)
- Important advantages
    - User code cannot inadvertently corrupt the state of an encapsulation object.
    - The implementation of an encapsulated class can change over time without requiring changes in user-level code.

### Exercise 7.20: When are friends useful? Discuss the pros and cons of using friends.

- `Friend` is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.
    - Pros:
        - the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
        - you can access all the nonpublic members conveniently.
        - sometimes, more readable to the users of class.
    - Cons:
        - lessens encapsulation and therefore maintainability.
        - code verbosity, declarations inside the class, outside the class.

### Exercise 7.21: Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work.

```cpp

class Sales_data {
    // To make a friend visible to users of the class, we usually declare each friend
    // (outside the class) in the same header as the class itself.
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    ...
}
