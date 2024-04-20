#include <iostream>
#include <string>
using namespace std;

const int NUM = 3;
const int ArSize = 12;

int show_result(int (*x)[ArSize], int n);

int main()
{
    const string months[ArSize] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };
    int sum, total, sales_volume[NUM][ArSize];

    for (int i = 0; i < NUM; i++)
    {
        cout << "Year " << i + 1 << ": " << endl;
        for (int j = 0; j < ArSize; j++)
        {
            cout << "Please enter number of books sold (";
            cout << months[j] << "): ";
            cin >> sales_volume[i][j];
        }
        cout << endl;
    }

    sum = total = show_result(sales_volume, 0);
    cout << "A total of " << sum << " <<C++ For Fools>> books were sold in the first year." << endl;
    total += sum = show_result(sales_volume, 1);
    cout << "A total of " << sum << " <<C++ For Fools>> books were sold in the second year." << endl;
    total += sum = show_result(sales_volume, 2);
    cout << "A total of " << sum << " <<C++ For Fools>> books were sold in the third year." << endl;
    cout << "A total of " << total << " <<C++ For Fools>> books were sold in three years." << endl;

    return 0;
}

int show_result(int (*x)[ArSize], int n)
{
    int sum = 0;

    for (int i = 0; i < ArSize; i++)
    {
        sum += x[n][i];
    }
    return sum;
}
