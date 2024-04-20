#include <iostream>
using namespace std;

long double sum_value()
{
    return 0;
}

template <typename T>
long double sum_value(const T &value)
{
    return value;
}

template <typename T, typename... Args>
long double sum_value(const T &value, const Args &...args)
{
    return value + sum_value(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    long y = 100000;
    char ch = 'x';
    cout << sum_value(n, x, y, ch, 'K', 66, 33.67);

    return 0;
}
