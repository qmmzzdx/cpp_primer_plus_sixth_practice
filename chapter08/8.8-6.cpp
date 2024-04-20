#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(T *arr, int n);

template <>
const char *maxn(const char *str[], int n);

int main()
{
    int test1[6] = {1, 3, 5, 7, 9, 11};
    double test2[4] = {10.0, 20.0, 15.0, 12.0};
    const char *test3[5] = {"123", "12345", "123456", "abcdefg", "xio"};

    cout << "The max of int array is: " << maxn(test1, 6) << endl;
    cout << "The max of double array is: " << maxn(test2, 4) << endl;
    cout << "The max of string array is: " << maxn(test3, 5) << endl;

    return 0;
}

template <typename T>
T maxn(T *arr, int n)
{
    T maxv = arr[0];

    for (int i = 0; i < n; i++)
    {
        maxv = max(maxv, arr[i]);
    }
    return maxv;
}

template <>
const char *maxn(const char *str[], int n)
{
    const char *maxv = *str;

    for (int i = 1; i < n; i++)
    {
        if (strlen(maxv) < strlen(str[i]))
        {
            maxv = str[i];
        }
    }
    return maxv;
}
