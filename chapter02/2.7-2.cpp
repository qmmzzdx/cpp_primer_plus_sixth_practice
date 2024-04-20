#include <iostream>
using namespace std;

const int YARD_PER_LONG = 220;

int main()
{
    double long_distance;

    cout << "Enter a distance for long unit: ";
    cin >> long_distance;

    cout << long_distance << " long distance ";
    cout << "is equal to ";
    long_distance *= YARD_PER_LONG;
    cout << long_distance << " yard distance." << endl;

    return 0;
}
