#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;

    cout << "Type, and I shall repeat(@ to quit)." << endl;
    while (cin.get(ch) && ch != '@')
    {
        ch = (islower(ch) ? toupper(ch) : tolower(ch));

        if (!isdigit(ch))
        {
            cout.put(ch);
        }
    }
    cout << "\nPlease excuse the slight confusion." << endl;

    return 0;
}
