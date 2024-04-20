#include <iostream>
using namespace std;

const double MINUTE_PER_DEGREE = 60.0;
const double SECOND_PER_MINUTE = 60.0;

int main()
{
    double degree, minute, second, total;

    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;

    total = degree + (minute / MINUTE_PER_DEGREE) + (second / (MINUTE_PER_DEGREE * SECOND_PER_MINUTE));
    cout << degree << " degrees, ";
    cout << minute << " minutes, ";
    cout << second << " seconds  = ";
    cout << total << " degrees" << endl;

    return 0;
}
