#include <iostream>
using namespace std;

const int MONTHS_PER_YEAR = 12;

int main()
{
    int age_total_months;

    cout << "Enter your age: ";
    cin >> age_total_months;

    age_total_months *= MONTHS_PER_YEAR;
    cout << "Your age includes " << age_total_months << " months." << endl;

    return 0;
}
