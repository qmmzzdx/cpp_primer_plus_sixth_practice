#include <iostream>
using namespace std;

const double TVARPS_5000 = 0.0;
const double TVARPS_5001_to_15000 = 0.1;
const double TVARPS_15001_to_35000 = 0.15;
const double TVARPS_35000 = 0.2;

int main()
{
    double wage, tax;

    cout << "Please enter your wage (q or <0 to quit): ";
    while (cin >> wage && wage > 0)
    {
        cout << "Your wage: " << wage << " tvarps.\n";
        if (wage < 5000)
        {
            tax = 0.0;
        }
        else if (wage < 15000)
        {
            tax = (wage - 5000) * TVARPS_5001_to_15000;
        }
        else if (wage < 35000)
        {
            tax = (wage - 15000) * TVARPS_15001_to_35000 + 10000 * TVARPS_5001_to_15000;
        }
        else
        {
            tax = (wage - 35000) * TVARPS_35000 + 20000 * TVARPS_15001_to_35000 + 10000 * TVARPS_5001_to_15000;
        }
        cout << "Your tax: " << tax << " tvarps.\n";
        cout << "Next wage (q or <0 to quit): ";
    }
    cout << "Bye." << endl;

    return 0;
}
