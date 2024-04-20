#include <iostream>
#include <string>
using namespace std;

struct car
{
    string producer;
    int year_of_introducion;
};

int main()
{
    int num;

    cout << "How many cars do you wish to catalog? ";
    (cin >> num).get();
    car *many_cars = new car[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << ':' << endl;
        cout << "Please enter the make: ";
        getline(cin, many_cars[i].producer);
        cout << "Please enter the year made: ";
        (cin >> many_cars[i].year_of_introducion).get();
    }

    cout << "Here is your collection:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << many_cars[i].year_of_introducion;
        cout << ' ' << many_cars[i].producer << endl;
    }
    delete[] many_cars;

    return 0;
}
