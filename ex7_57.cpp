// Exercise 7.57: Write your own version of the Account class.

#ifndef CP5_ex7_57_h
#define CP5_ex7_57_h

#include <string>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    std::string owner;
    double amount;
    // static members exist outside any object.
    static double interestRate;
    // we can provide in-class initializers for static members that have const integral
    // type and must do so for static members that are constexpr s of literal type
    static constexpr double todayRate = 42.42;
    // static member functions are not bound to any object
    // we can define a static member function inside or outside of the class body.
    //     When we define a static member outside the class, we do not repeat the static keyword.
    static double initRate() { return todayRate; }
};

// static members are not initialized by the class’ constructors.
// we can define and initialize each static data member outside the class body
// The best way to ensure that the object is defined exactly once is to put the
//     definition of static data members in the same file
double Account::interestRate = initRate();

#endif