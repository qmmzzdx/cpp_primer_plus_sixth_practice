#include <iostream>
#include "sales.h"

namespace SALES
{
    Sales::Sales(double ar[], int n)
    {
        double total = 0.0, max = ar[0], min = ar[0];
        for (int i = 1; i < n; i++)
        {
            this->sales[i] = ar[i], total += ar[i];
            max = ar[i] > max ? ar[i] : max;
            min = ar[i] < min ? ar[i] : min;
        }
        this->min = min;
        this->max = max;
        this->average = total / n;
    }

    Sales::Sales()
    {
        using namespace std;
        int len;
        cout << "Enter the length of sales(<= 4 and > 0): ";
        while (!(cin >> len) || len > 4 || len <= 0)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
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
                    continue;
                cout << "Please enter a number: ";
            }
        }
        *this = Sales(temp, len);
        delete[] temp;
    }

    void Sales::show_sales() const
    {
        std::cout << "Sales average: " << this->average << std::endl;
        std::cout << "Sales max: " << this->max << std::endl;
        std::cout << "Sales min: " << this->min << std::endl;
    }
}
