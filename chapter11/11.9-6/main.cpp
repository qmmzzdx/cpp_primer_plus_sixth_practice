#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    double val;
    Stonewt minv, maxv;
    Stonewt temp(11, 0.0);
    Stonewt wt[6] = {Stonewt(285.7), Stonewt(21, 8), Stonewt(12.0)};

    int count = 0;
    for (int i = 3; i < 6; i++)
    {
        cout << "Please enter an number for pounds: ";
        while (!(cin >> val))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Illegal input! Enter an number: ";
        }
        wt[i] = Stonewt(i + 1, val);
    }
    minv = maxv = wt[0];
    for (int i = 0; i < 6; i++)
    {
        minv = wt[i] < minv ? wt[i] : minv;
        maxv = wt[i] > maxv ? wt[i] : maxv;
        count += wt[i] >= temp;
    }
    cout << "The minimum pounds are: " << minv;
    cout << "The maximum pounds are: " << maxv;
    cout << "There are " << count << " elements more than 11 stones." << endl;

    return 0;
}
