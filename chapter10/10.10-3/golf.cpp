#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char *name, int hc)
{
    strncpy(this->fullname, name, 40);
    this->fullname[39] = '\0';
    this->handicap = hc;
}

Golf::Golf()
{
    using std::cin;
    using std::cout;
    char tempname[40];
    int temphandicap;

    cout << "Please enter the fullname(enter to quit): ";
    cin.getline(tempname, Len);
    cout << "Please enter the handicap: ";
    while (!(cin >> temphandicap))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Please enter an number: ";
    }
    cin.get();
    *this = Golf(tempname, temphandicap);
}

void Golf::set_handicap(int hc)
{
    this->handicap = hc;
}

void Golf::showgolf() const
{
    using namespace std;
    cout << "Name: " << this->fullname << endl;
    cout << "Handicap: " << this->handicap << endl;
}
