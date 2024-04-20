#include <iostream>
using namespace std;

void print_string(const char *str, int n = 0);

int main()
{
    const char *str = "This is a test.";

    cout << "Only one parameter, print 1 times:" << endl;
    print_string(str);
    cout << "Having two parameter can print 2 times:" << endl;
    print_string(str, 3);
    cout << "Bye." << endl;

    return 0;
}

void print_string(const char *str, int n)
{
    static int count = 1;

    for (int i = 0; i < count; ++i)
    {
        cout << str << endl;
    }
    ++count;
}
