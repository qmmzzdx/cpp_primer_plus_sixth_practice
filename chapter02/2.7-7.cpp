#include <iostream>
using namespace std;

void show_time(int hour, int minute);

int main()
{
    int hour, minute;

    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minute;
    show_time(hour, minute);

    return 0;
}

void show_time(int hour, int minute)
{
    cout << "Time: " << hour << ":" << minute << endl;
}
