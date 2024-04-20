#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<double, 3> scores;

    cout << "Please enter your the results of the first 40 meter race: ";
    cin >> scores[0];
    cout << "Please enter your the results of the second 40 meter race: ";
    cin >> scores[1];
    cout << "Please enter your the results of the third 40 meter race: ";
    cin >> scores[2];

    cout << "You ran three times in total." << endl;
    cout << "Your average score is ";
    cout << (scores[0] + scores[1] + scores[2]) / 3.0 << "." << endl;

    return 0;
}
