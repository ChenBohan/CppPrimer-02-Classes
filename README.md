# CppPrimer-02-Classes
Solutions for Chapter 7.Classes exercises of C++ Primer 5th.

#### Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p.76).

Any direct use of a member of the class is assumed to be an implicit reference through `this` .

```cpp
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

#### Exercise 7.9: Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).

```cpp
std::ostream& print(std::ostream &os, const Person& person) {
    return os << person.name << " " << person.address;
}

std::istream& read(std::istream &is, Person& person) {
    return is >> person.name >> person.address;
}
```

#### Exercise 7.11: Add constructors to your Sales_data class and write a program to use each of the constructors.

```cpp
// needed because Sales_data has another constructor
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
#### Exercise 7.13: Rewrite the program from page 255 to use the istream constructor.

```cpp
std::istream &is = std::cin;
while (is) {
    Sales_data trans(is);
    ...
```

#### Exercise 7.17: What, if any, are the differences between using class or struct?

- The only difference between using class and using struct to define a class is the default access level. (class : private, struct : public)

#### Exercise 7.18: What is encapsulation? Why is it useful?

- encapsulation
    - encapsulation is the separation of implementation from interface. It hides the implementation details of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class)
- Important advantages
    - User code cannot inadvertently corrupt the state of an encapsulation object.
    - The implementation of an encapsulated class can change over time without requiring changes in user-level code.

#### Exercise 7.20: When are friends useful? Discuss the pros and cons of using friends.
h__bmw_
- `Friend` is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.
    - Pros:
        - the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
        - you can access all the nonpublic members conveniently.
        - sometimes, more readable to the users of class.
    - Cons:
        - lessens encapsulation and therefore maintainability.
        - code verbosity, declarations inside the class, outside the class.

#### Exercise 7.21: Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work.

```cpp

class Sales_data {
    // To make a friend visible to users of the class, we usually declare each friend
    // (outside the class) in the same header as the class itself.
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    ...
}
```

#### Exercise 7.23: Write your own version of the Screen class.

```cpp
// type members usually appear at the beginning of the class.
// = typedef std::string::size_type pos;
using pos = std::string::size_type;
```

#### Exercise 7.25: Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?

- synthesized version work correctly
    - for classes that have vector or string members.
- synthesized version doesn't work correctly
    - for classes that allocate resources that reside outside the class objects themselves.
- Hence the class below which used only built-in type and strings can rely on the default version of copy and assignment.

#### Exercise 7.26: Define Sales_data::avg_price as an inline function.

- member functions defined inside the class are automatically inline
- Although we are not required to do so, it is legal to specify inline on both the
declaration and the definition. specifying inline only on the definition outside the class can make the class easier to read.
- For the same reasons that we define inline functions in headers inline member functions should be defined in the same header as the corresponding class definition.


```cpp
inline double avg_price() const;
...
inline double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}
```

#### Exercise 7.28: What would happen in the previous exercise if the return type of move , set, and display was Screen rather than Screen&?

The second call to `display` couldn't print # among the output, cause the call to `set` would change the temporary copy, not myScreen.

#### Exercise 7.30: It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.

- Pros
    - more explicit
    - less scope for misreading
    - can use the member function parameter which name is same as the member name.
```cpp
void setAddr(const std::string &addr) { this->addr = addr; }
```

- Cons
    - more to read
    - sometimes redundant
```
std::string getAddr() const { return this->addr; } // unnecessary
```

#### Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X .

```cpp
// After a declaration and before a definition is seen, the type Screen is an incomplete type
// We can define pointers or references to such types, and we can declare (but not define)
// functions that use an incomplete type as a parameter or return type.
class Y;

class X {
    Y* y = nullptr;
};

class Y {
    X x;
};
```

#### Exercise 7.36: The following initializer is in error. I dentify and fix the problem.
```cpp
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```
- In this case, the constructor initializer makes it appear as if `base` is initialized with `i` and then `base` is used to initialize `rem`. However, `rem` is initialized first. The effect of this initializer is to initialize `rem` with the undefined value of `base`!
- Members are initialized in the order in which they appear in the class definition. The order in which initializers appear in the constructor initializer list does not change the order of initialization.
- It is a good idea to write constructor initializers in the same order as the members are declared. Moreover, when possible, avoid using members to initialize other members.


