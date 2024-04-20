#include <iostream>
using namespace std;

int initialize_array(double arr[], int n);
void show_array(const double arr[], int n);
void count_average(const double arr[], int n);

const int ArSize = 10;

int main()
{
    double golf[ArSize];

    int n = initialize_array(golf, ArSize);
    show_array(golf, n);
    count_average(golf, n);
    cout << "Bye." << endl;

    return 0;
}

int initialize_array(double arr[], int n)
{
    int i = 0;

    cout << "You can enter up to " << ArSize;
    cout << " golf scores (q to terminate)." << endl;

    cout << "Golf scores #1: ";
    while (i < n && cin >> arr[i])
    {
        if (++i < ArSize)
        {
            cout << "Golf scores #" << i + 1 << ": ";
        }
    }
    return i;
}

void show_array(const double arr[], int n)
{
    cout << "All golf scores:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void count_average(const double arr[], int n)
{
    double aver = 0.0;

    for (int i = 0; i < n; i++)
    {
        aver += arr[i];
    }
    aver /= n;
    cout << "Average golf scores: " << aver << endl;
}
