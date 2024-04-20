#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg()
{
    strcpy(fullname, "Plorga");
}

void Plorg::reset_ci()
{
    using std::cin;
    using std::cout;
    int my_ci;

    cout << "Please enter an new ci number: ";
    while (!(cin >> my_ci))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Please enter an number: ";
    }
    this->ci = my_ci;
}

void Plorg::show_plorg() const
{
    using std::cout;
    using std::endl;

    cout << "The plorg name is: " << this->fullname << endl;
    cout << "The plorg ci is: " << this->ci << endl;
}

void Plorg::create_new_plorg(const char *newname)
{
    strncpy(fullname, newname, 19);
    fullname[19] = '\0';
    this->ci = 50;
}
