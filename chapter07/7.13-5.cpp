#include <iostream>
using namespace std;

long long factorial(long long n);

int main()
{
    long long temp;

    cout << "Please enter a number(<0 or q to quit): ";
    while (cin >> temp && temp >= 0)
    {
        cout << temp << "! = " << factorial(temp) << endl;
        cout << "Next number(<0 or q to quit): ";
    }
    cout << "Bye." << endl;

    return 0;
}

long long factorial(long long n)
{
    return n > 0 ? n * factorial(n - 1) : 1;
}
