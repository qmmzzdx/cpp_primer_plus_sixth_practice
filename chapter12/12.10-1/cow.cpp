#include <iostream>
#include "cow.h"
#include <cstring>

Cow::Cow()
{
    std::strcpy(name, "\0");
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    std::strncpy(name, nm, 20);
    name[19] = '\0';
    hobby = new char[strlen(ho) + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    std::strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow &Cow::operator=(const Cow &c)
{
    if (this != &c)
    {
        delete[] hobby;
        std::strcpy(name, c.name);
        hobby = new char[strlen(c.hobby) + 1];
        std::strcpy(hobby, c.hobby);
        weight = c.weight;
    }
    return *this;
}

void Cow::ShowCow() const
{
    std::cout << "Cow name: " << name << std::endl;
    std::cout << "Cow hobby: " << hobby << std::endl;
    std::cout << "Cow weight: " << weight << "\n\n";
}
