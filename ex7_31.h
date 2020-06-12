// Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to
// Y, and Y has an object of type X .

#ifndef EX7_31_H
#define EX7_31_H

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

#endif


