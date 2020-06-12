// Exercise 7.32: Define your own versions of Screen and Window_mgr in
// which clear is a member of Window_mgr and a friend of Screen

#ifndef EX7_32_H
#define EX7_32_H

#include <vector>
#include <string>
#include <iostream>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    // type members usually appear at the beginning of the class.
    // = typedef std::string::size_type pos;
    using pos = std::string::size_type;

    // needed because Screen has another constructor
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    // implicitly uses the in-class initializer for the cursor member
    char get(pos r, pos c) const { return contents[r * width + c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);
    const Screen& display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    Screen& display(std::ostream &os) {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &os) const {
        os << contents;
    }
};

inline Screen& Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

inline void Window_mgr::clear(ScreenIndex i) {
    if (i >= screens.size())
        return;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif