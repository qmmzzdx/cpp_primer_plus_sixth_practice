#include <iostream>
#include <string>
using namespace std;

bool ispalindrome(const string &s);

int main()
{
    string s;

    cout << "Please enter a string (q to quit): ";
    while (getline(cin, s) && s != "q")
    {
        cout << "\"" << s << "\"";
        cout << (ispalindrome(s) ? " is " : " isn't ");
        cout << "a palindrome string." << endl;
        cout << "You can enter again (q to quit): ";
    }
    cout << "Done." << endl;

    return 0;
}

bool ispalindrome(const string &s)
{
    return s == string(s.rbegin(), s.rend());
}
