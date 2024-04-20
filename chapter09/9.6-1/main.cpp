#include <iostream>
#include "golf.h"
using namespace std;

int main()
{
    int sum = 0;
    golf andy[Len];

    setgolf(andy[0], "Ann Birdfree", 24);
    cout << "Starting output:" << endl;
    showgolf(andy[0]);

    handicap(andy[0], 666);
    cout << "Changing handicap:" << endl;
    showgolf(andy[0]);

    for (int i = 0; i < Len; i++)
    {
        cout << "Please enter andy #" << i + 1 << ": " << endl;
        if (0 == setgolf(andy[i]))
        {
            break;
        }
        ++sum;
    }
    if (sum > 0)
    {
        cout << "Ending output:" << endl;
    }
    for (int i = 0; i < sum; i++)
    {
        showgolf(andy[i]);
    }
    cout << "Bye." << endl;

    return 0;
}
