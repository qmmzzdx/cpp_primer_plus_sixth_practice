#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void print_upper_string(string &str);

int main()
{
    string str;

    cout << "Enter a string (q to quit): ";
    while (getline(cin, str) && str != "q")
    {
        print_upper_string(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
    }
    cout << "Bye." << endl;

    return 0;
}

void print_upper_string(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}
