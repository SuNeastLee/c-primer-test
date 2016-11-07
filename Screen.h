#ifndef Screen_and_Window_mgr
#define Screen_and_Window_mgr

#include<iostream>
#include<string>

class Screen {
public:
    typedef std::string::size_type pos;
    
    //structure function
    Screen() = default;
    Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd, ' '){}
    Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd, c){}
    
    //function
    void some_member() const;
    char get(){ return contents[cursor]; }
    inline char get(pos hi, pos wi) const;
    Screen &move(pos r, pos c);
    inline Screen set(char c){ contents[cursor] = c; return *this;}
    inline Screen set(pos hi, pos wd, char c){ contents[hi*width + wd] = c; return *this; }
    Screen &display(std::ostream os){ do_display(os); return *this; }
    const Screen display(){ do_display(os); return *this; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0;//whether set 0 as the value ?
    Screen do_display(std::ostream &os) const {os << contents;} 
};

class Window_mgr {
private:
    std::vector<Screen> screens { Screen(24,80, ' ') };
};


inline
Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos hi, pos wi) const
{
    pos row = r * width;
    return contents[row + c];
}
void Screen::some_member() const
{
    ++access_ctr;
}

#endif
