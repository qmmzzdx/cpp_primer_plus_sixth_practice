#include "winec.h"

Wine::Wine(const char *l, int y) : string(l)
{
    PairArray::operator=(PairArray(ArrayInt(y), ArrayInt(y))); //使用隐式赋值运算符调用私有对象构造函数进行初始化;
    year = y;
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[]) : string(l)
{
    PairArray::operator=(PairArray(ArrayInt(yr, y), ArrayInt(bot, y))); //使用隐式赋值运算符调用私有对象构造函数进行初始化;
    year = y;
}

Wine::~Wine()
{
}

void Wine::GetBottles()
{
    ArrayInt yr(year);
    ArrayInt bt(year);

    cout << "Enter " << (const string &)*this;
    cout << " data for " << year << " year(s):" << endl;
    for (int i = 0; i < year; i++)
    {
        cout << "Enter year: ";
        cin >> yr[i];
        cout << "Enter bottles for that year: ";
        cin >> bt[i];
    }
    PairArray::operator=(PairArray(yr, bt));
}

string &Wine::Label()
{
    return (string &)*this; //使用强制类型转换访问私有对象;
}

int Wine::sum() const
{
    return PairArray::Sum();
}

void Wine::Show() const
{
    cout << "Wine: " << (const string &)(*this) << endl;
    cout << "\tYear\tBottles" << endl;
    PairArray::Show(year);
}
