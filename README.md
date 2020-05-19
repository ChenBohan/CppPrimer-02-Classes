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
Sales_data() = default;
Sales_data(const std::string& s): bookNo(s) {}
Sales_data(const std::string& s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) {}
Sales_data(std::istream& is);
```

