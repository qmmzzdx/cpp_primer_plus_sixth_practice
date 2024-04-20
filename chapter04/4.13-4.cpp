#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fname, lname;

    cout << "Enter your first name: ";
    getline(cin, fname);
    cout << "Enter your last name: ";
    getline(cin, lname);

    lname += ", " + fname;
    cout << "Here's the information in a single string: ";
    cout << lname << endl;

    return 0;
}
