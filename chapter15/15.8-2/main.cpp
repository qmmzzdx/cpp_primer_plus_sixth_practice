#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y;
            cout << " is " << z << endl;
            z = gmean(x, y);
            cout << "Geometric mean of " << x << " and " << y;
            cout << " is " << z << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_hmean &bg)
        {
            cout << bg.what(); //调用what方法打印hmean中的异常;
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean &hg)
        {
            cout << hg.what(); //调用what方法打印gmean中的异常;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";

    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        throw bad_hmean();
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
    {
        throw bad_gmean();
    }
    return std::sqrt(a * b);
}
