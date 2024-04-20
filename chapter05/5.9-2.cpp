#include <iostream>
#include <array>
using namespace std;

const int ArSize = 101;

int main()
{
    array<long double, ArSize> factorials;

    factorials[0] = factorials[1] = 1L;
    for (int i = 2; i < ArSize; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }
    for (int i = 0; i < ArSize; i++)
    {
        cout << i << "! = " << factorials[i] << endl;
    }

    return 0;
}
