#ifndef WINEC_H_
#define WINEC_H_
#include <string>
#include <valarray>
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
private:
    T1 year;
    T2 bottles;

public:
    Pair() {}
    Pair(const T1 &yr, const T2 &bt) : year(yr), bottles(bt) {}
    int Sum() const;
    void Show(int y) const;
};

template <typename T1, typename T2>
int Pair<T1, T2>::Sum() const
{
    return bottles.sum();
}

template <typename T1, typename T2>
void Pair<T1, T2>::Show(int y) const
{
    for (int i = 0; i < y; i++)
    {
        cout << '\t' << year[i] << '\t' << bottles[i] << endl;
    }
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private string, private PairArray
{
private:
    int year;

public:
    Wine(const char *l, int y);
    Wine(const char *l, int y, const int yr[], const int bot[]);
    ~Wine();
    void GetBottles();
    string &Label();
    int sum() const;
    void Show() const;
};

#endif
