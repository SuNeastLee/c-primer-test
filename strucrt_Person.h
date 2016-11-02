#ifndef Person
#define Person

#include<iostream>
#include<string>

struct Person {
    std::string getName() const { return name; }
    std::string getAddr() const { return address; }
    
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
