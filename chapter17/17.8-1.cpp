#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 256;

int main()
{
    char ch, str[MAXN];

    cout << "Please enter a string ($ to quit): ";
    cin.get(str, MAXN, '$');
    cout << "Your input: " << str << endl;
    cout << "Length: " << strlen(str) << endl;
    cout << "Other messages: ";
    while ((ch = cin.get()) != '\n')
    {
        cout << ch;
    }

    return 0;
}
