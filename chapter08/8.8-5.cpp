#include <iostream>
using namespace std;

template <typename T>
T max5(const T *array);

int main()
{
    int test1[5] = {1, 3, 5, 7, 9};
    double test2[5] = {10.0, 20.0, 15.0, 12.0, 30.0};

    cout << "The max of int array is: " << max5(test1) << endl;
    cout << "The max of double array is: " << max5(test2) << endl;

    return 0;
}

template <typename T>
T max5(const T *array)
{
    T maxv = array[0];

    for (int i = 1; i < 5; i++)
    {
        maxv = max(maxv, array[i]);
    }
    return maxv;
}
