#ifndef Person
#define Person

#include<iostream>
#include<string>

struct Person {
    
friend std::istream &read(std::istream &, Person &);
friend std::ostream &print(std::ostream &, const Person &);
    
public:
    Person = default;
    Person(const std::string sname, const std::string saddr): name(sname),address(saddr) { }
    Person(std::istream &is){ read(is,*this); }
    
    std::string getName() const { return name; }
    std::string getAddr() const { return address; }
    
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >>" ">> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name <<" "<< person.address;
    return os;
}

#endif
