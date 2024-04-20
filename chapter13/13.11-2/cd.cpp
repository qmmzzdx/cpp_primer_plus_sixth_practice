#include <iostream>
#include "cd.h"
#include <cstring>

Cd::Cd(const char *s1, const char *s2, int n, double x) //用户定义构造函数;
{
    performers = new char[std::strlen(s1) + 1];
    std::strcpy(performers, s1);
    labels = new char[std::strlen(s2) + 1];
    std::strcpy(labels, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d) //用户定义构造函数;
{
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    labels = new char[std::strlen(d.labels) + 1];
    std::strcpy(labels, d.labels);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() //用户定义默认构造函数;
{
    performers = new char[1];
    performers[0] = '\0';
    labels = new char[1];
    labels[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete[] performers;
    delete[] labels;
}

void Cd::Report() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << labels << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d) //重载赋值运算符;
{
    if (this == &d)
    {
        return *this;
    }
    delete[] performers; //释放原有已分配的内存空间;
    delete[] labels;     //同上;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    labels = new char[std::strlen(d.labels) + 1];
    std::strcpy(labels, d.labels);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
