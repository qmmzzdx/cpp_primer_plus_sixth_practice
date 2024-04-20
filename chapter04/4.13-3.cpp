#include <iostream>
#include <cstring>
using namespace std;

const int ArSize = 20;

int main()
{
    char fname[ArSize];
    char lname[ArSize];

    cout << "Enter your first name: ";
    cin.getline(fname, ArSize);
    cout << "Enter your last name: ";
    cin.getline(lname, ArSize);

    char *name = new char[strlen(fname) + strlen(lname) + 5];
    strcpy(name, lname);
    strcat(name, ", ");
    strcat(name, fname);

    cout << "Here's the information in a single string: ";
    cout << name << endl;
    delete[] name;

    return 0;
}
