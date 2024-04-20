#include <iostream>
using namespace std;

int main()
{
    double kilometer, liter;

    cout << "Please enter your driving distance(km): ";
    cin >> kilometer;
    cout << "Please enter your gas consumption(liter): ";
    cin >> liter;

    cout << "You consume " << liter / kilometer * 100;
    cout << " liter gas for driving per 100 km." << endl;

    return 0;
}
