#include <iostream>
#include "cd.h"
#include <cstring>

Cd::Cd(const char *s1, const char *s2, int n, double x) //用户定义构造函数;
{
    std::strncpy(performers, s1, 50);
    performers[49] = '\0';
    std::strncpy(labels, s2, 20);
    labels[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d) //用户定义构造函数;
{
    std::strncpy(performers, d.performers, 50);
    performers[49] = '\0';
    std::strncpy(labels, d.labels, 50);
    labels[49] = '\0';
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() //用户定义默认构造函数;
{
    performers[0] = '\0';
    labels[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << labels << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d)
{
    if (this == &d)
    {
        return *this;
    }
    std::strncpy(performers, d.performers, 50);
    performers[49] = '\0';
    std::strncpy(labels, d.labels, 20);
    labels[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
