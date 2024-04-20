#include <iostream>
using namespace std;

double harmonic_mean(double x, double y);

int main()
{
    double a, b;

    cout << "Please enter two numbers (0 to quit): ";
    while (cin >> a >> b && a && b)
    {
        cout << "The harmonic mean of " << a;
        cout << " and " << b << " is ";
        cout << harmonic_mean(a, b) << endl;
        cout << "Next two numbers (0 to quit): ";
    }
    cout << "Bye." << endl;

    return 0;
}

double harmonic_mean(double x, double y)
{
    return 2.0 * x * y / (x + y);
}
