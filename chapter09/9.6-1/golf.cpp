#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf &g, const char *name, int hc)
{
    strncpy(g.fullname, name, Len);
    g.fullname[Len - 1] = '\0';
    g.handicap = hc;
    return;
}

int setgolf(golf &g)
{
    using std::cin;
    using std::cout;
    cout << "Please enter the fullname(enter to quit): ";
    cin.getline(g.fullname, Len);
    if (0 == strcmp(g.fullname, "\0"))
    {
        return 0;
    }
    cout << "Please enter the handicap: ";
    while (!(cin >> g.handicap))
    {
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }
        cout << "Please enter an number: ";
    }
    cin.get();
    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    std::cout << "Name: " << g.fullname << std::endl;
    std::cout << "Handicap: " << g.handicap << std::endl;
}
