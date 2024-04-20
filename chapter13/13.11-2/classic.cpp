#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic() : Cd()
{
    cdstr = new char[1];
    cdstr[0] = '\0';
}

Classic::Classic(const char *s, const char *s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    cdstr = new char[std::strlen(s) + 1];
    std::strcpy(cdstr, s);
}

Classic::Classic(const char *s, const Cd &d) : Cd(d)
{
    cdstr = new char[std::strlen(s) + 1];
    std::strcpy(cdstr, s);
}

Classic::~Classic()
{
    delete[] cdstr;
}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Major article in the CD is: " << cdstr << std::endl;
    std::cout.put('\n');
}

Classic &Classic::operator=(const Classic &cs)
{
    if (this == &cs)
    {
        return *this;
    }
    delete[] cdstr;
    Cd::operator=(cs);
    cdstr = new char[std::strlen(cs.cdstr) + 1];
    std::strcpy(cdstr, cs.cdstr);
    return *this;
}
