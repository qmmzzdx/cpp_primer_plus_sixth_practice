#include <iostream>
using namespace std;

int main()
{
    int num1, num2, sum = 0;

    cout << "Please enter the first integer: ";
    cin >> num1;
    cout << "Please enter the second integer: ";
    cin >> num2;

    for (int i = num1; i <= num2; i++)
    {
        sum += i;
    }
    cout << "Sum of " << num1 << " to " << num2 << " are " << sum << endl;

    return 0;
}
