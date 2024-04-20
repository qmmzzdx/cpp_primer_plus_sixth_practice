#include <iostream>
#include <cstring>
#include "person.h"

Person::Person(const string &ln, const char *fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    std::cout << "The name format is:" << endl;
    std::cout << fname << "(firstname), ";
    std::cout << lname << "(lastname).";
}

void Person::FormalShow() const
{
    std::cout << "The name format is:" << endl;
    std::cout << lname << "(lastname), ";
    std::cout << fname << "(firstname)." << endl;
}
