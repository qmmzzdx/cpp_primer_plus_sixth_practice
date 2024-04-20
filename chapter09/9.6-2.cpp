#include <iostream>
#include <string>
using namespace std;

void strcount(const string &str);

int main()
{
    string input;

    cout << "Enter a line:\n";
    while (getline(cin, input), input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
    }
    cout << "Bye" << endl;

    return 0;
}

void strcount(const string &str)
{
    static int total = 0;

    cout << "\"" << str << "\" contains ";
    total += str.size();
    cout << str.size() << " characters\n";
    cout << total << " characters total\n";
}
