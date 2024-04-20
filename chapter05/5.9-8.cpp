#include <iostream>
#include <cstring>
using namespace std;

const int ArSize = 256;

int main()
{
    char str[ArSize];
    unsigned int count = 0;

    cout << "Enter words (to stop, type the word done):" << endl;
    while (cin >> str, strcmp("done", str))
    {
        ++count;
    }
    cout << "You entered a total of " << count << " words." << endl;

    return 0;
}
