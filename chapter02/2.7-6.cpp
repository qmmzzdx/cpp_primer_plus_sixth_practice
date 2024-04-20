#include <iostream>
using namespace std;

const int ASTRONOMICAL_UNITS_PER_LIGHT_YEARS = 63240;

double transform(double temp);

int main()
{
    double light_years;

    cout << "Enter the number of light years: ";
    cin >> light_years;
    cout << light_years << " light years = ";
    cout << transform(light_years);
    cout << " astronomical units." << endl;

    return 0;
}

double transform(double temp)
{
    return temp * ASTRONOMICAL_UNITS_PER_LIGHT_YEARS;
}
