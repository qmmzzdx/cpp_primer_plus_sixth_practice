#include <iostream>
using namespace std;

int Fill_array(double arr[], int n);
void Show_array(const double arr[], int n);
void Reverse_array(double arr[], int n);

const int ArSize = 10;

int main()
{
    double arr[ArSize];

    int n = Fill_array(arr, ArSize);
    Show_array(arr, n);
    Reverse_array(arr, n);
    Show_array(arr, n);
    Reverse_array(arr + 1, n - 2);
    Show_array(arr, n);
    cout << "Bye." << endl;

    return 0;
}

int Fill_array(double arr[], int n)
{
    int i = 0;

    cout << "You can enter up to " << ArSize;
    cout << " numbers (q to terminate)." << endl;
    cout << "Number #1: ";
    while (i < n && cin >> arr[i])
    {
        if (++i < ArSize)
        {
            cout << "Number #" << i + 1 << ": ";
        }
    }
    return i;
}

void Show_array(const double arr[], int n)
{
    cout << "All numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void Reverse_array(double arr[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}
