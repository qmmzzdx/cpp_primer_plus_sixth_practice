#include <iostream>
using namespace std;

double temperature(double temp);

int main()
{
    double celsius;

    cout << "Please enter a Celsius value: ";
    cin >> celsius;
    cout << celsius << " degrees Celsius is ";
    cout << temperature(celsius);
    cout << " degrees Fahrenheit." << endl;

    return 0;
}

double temperature(double temp)
{
    return 1.8 * temp + 32.0;
}
