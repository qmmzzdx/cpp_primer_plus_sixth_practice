#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic(const char *s, const char *s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    std::strncpy(cdstr, s, 50);
    cdstr[49] = '\0';
}

Classic::Classic(const char *s, const Cd &d) : Cd(d)
{
    std::strncpy(cdstr, s, 50);
    cdstr[49] = '\0';
}

Classic::~Classic()
{
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
    Cd::operator=(cs);
    std::strncpy(cdstr, cs.cdstr, 50);
    cdstr[49] = '\0';
    return *this;
}
