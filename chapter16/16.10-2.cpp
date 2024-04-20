#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

string ToLower(string &st);
bool ispalindrome(const string &s);

int main()
{
    string s;

    cout << "Please enter a string (q to quit): ";
    while (getline(cin, s) && s != "q")
    {
        s = ToLower(s);
        cout << "\"" << s << "\"";
        cout << (ispalindrome(s) ? " is " : " isn't ");
        cout << "a palindrome string." << endl;
        cout << "You can enter again (q to quit): ";
    }
    cout << "Done." << endl;

    return 0;
}

string ToLower(string &st)
{
    string s;
    for (auto &x : st)
    {
        if (!isspace(x) && !ispunct(x))
        {
            s += tolower(x);
        }
    }
    return s;
}

bool ispalindrome(const string &s)
{
    return s == string(s.rbegin(), s.rend());
}
