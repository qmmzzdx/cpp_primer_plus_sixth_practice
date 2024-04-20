#include <iostream>
#include "sales.h"

namespace SALES
{
    void setSales(Sales &s, const double ar[], int n)
    {
        double total = ar[0], maxv = ar[0], minv = ar[0];
        for (int i = 1; i < n; i++)
        {
            s.sales[i] = ar[i], total += ar[i];
            maxv = ar[i] > maxv ? ar[i] : maxv;
            minv = ar[i] < minv ? ar[i] : minv;
        }
        s.min = minv, s.max = maxv, s.average = total / n;
    }
    void setSales(Sales &s)
    {
        using namespace std;
        int len;
        cout << "Enter the length of sales(<= 4 and > 0): ";
        while (!(cin >> len) || len > 4 || len <= 0)
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Please enter a number(<= 4 and > 0): ";
        }
        double *temp = new double[len];
        cout << "Please enter the sales:" << endl;
        for (int i = 0; i < len; i++)
        {
            cout << "Please enter the content #" << i + 1 << ": ";
            while (!(cin >> temp[i]))
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "Please enter a number: ";
            }
        }
        setSales(s, temp, len);
        delete[] temp;
    }
    void showSales(const Sales &s)
    {
        std::cout << "Sales average: " << s.average << std::endl;
        std::cout << "Sales max: " << s.max << std::endl;
        std::cout << "Sales min: " << s.min << std::endl;
    }
}
