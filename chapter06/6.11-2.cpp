#include <iostream>
#include <array>
using namespace std;

const int ArSize = 10;

int main()
{
    int i = 0, j = 0;
    unsigned int count = 0;
    array<double, ArSize> donations;
    double total = 0.0, average = 0.0;

    cout << "You may enter up to " << ArSize;
    cout << " donation (q to terminate)." << endl;
    cout << "donation #1: ";
    while (i < ArSize && cin >> donations[i])
    {
        if (++i < ArSize)
        {
            cout << "donation #" << i + 1 << ": ";
        }
    }

    for (j = 0; j < i; j++)
    {
        total += donations[j];
    }
    average = total / i;
    for (j = 0; j < i; j++)
    {
        count += (average < donations[j] ? 1 : 0);
    }

    if (i > 0)
    {
        cout << "Average of " << i << " donations is " << average << endl;
        cout << count << " number" << (count > 1 ? "s are " : " is ") << "greater than the average." << endl;
    }
    else
    {
        cout << "No donation!" << endl;
    }

    return 0;
}
