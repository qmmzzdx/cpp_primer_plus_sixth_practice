#include <iostream>
#include "stonewt.h"
using std::cout;
using std::endl;

void Stonewt::set_stone()
{
    stone = int(pounds) / Lbs_per_stn;                           //设置stone英石变量;
    pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds); //设置pounds磅数剩余变量;
}

void Stonewt::set_pounds()
{
    pounds = stone * Lbs_per_stn + pds_left; //设置pounds英镑变量;
}

void Stonewt::set_pounds_int()
{
    pounds_int = int(pounds + 0.5); //设置pounds英镑整型四舍五入变量;
}

Stonewt::Stonewt(double lbs, Mode form)
{
    mode = form;
    if (mode == STONE)
    {
        stone = int(lbs) / Lbs_per_stn;
        pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
        set_pounds();     //调用函数设置Stonewt类剩余数据;
        set_pounds_int(); //同上;
    }
    else if (mode == INT_POUND)
    {
        pounds_int = int(lbs);
        pounds = lbs;
        set_stone();
    }
    else if (mode == DOUBLE_POUND)
    {
        pounds = lbs;
        set_pounds_int();
        set_stone();
    }
    else
    {
        cout << "Incorrect mode!" << endl;
        cout << "Stonewt set to 0" << endl;
        stone = pounds = pds_left = 0.0;
        mode = STONE;
    }
}

Stonewt::Stonewt(int stn, double lbs, Mode form)
{
    mode = form;
    if (mode == STONE)
    {
        stone = stn;
        pds_left = lbs;
        set_pounds();
        set_pounds_int();
    }
    else if (mode == INT_POUND)
    {
        pounds_int = int(stn * Lbs_per_stn + lbs);
        pounds = stn * Lbs_per_stn + lbs;
        set_stone();
    }
    else if (mode == DOUBLE_POUND)
    {
        pounds = stn * Lbs_per_stn + lbs;
        set_pounds_int();
        set_stone();
    }
    else
    {
        cout << "Incorrect mode!" << endl;
        cout << "Stonewt set to 0" << endl;
        stone = pounds = pds_left = 0.0;
        mode = STONE;
    }
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0.0;
    mode = STONE;
}

Stonewt::~Stonewt()
{
}

void Stonewt::set_stone_mode()
{
    mode = STONE;
}

void Stonewt::set_pounds_mode()
{
    mode = DOUBLE_POUND;
}

void Stonewt::set_int_pounds_mode()
{
    mode = INT_POUND;
}

Stonewt Stonewt::operator+(const Stonewt &st) const
{
    return Stonewt(pounds + st.pounds, st.mode); //调用构造函数进行加法操作并重新设置mode模式;
}

Stonewt Stonewt::operator-(const Stonewt &st) const
{
    return Stonewt(pounds - st.pounds, st.mode); //调用构造函数进行减法操作并重新设置mode模式;
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n, mode); //调用构造函数进行乘法操作并重新设置mode模式;
}

Stonewt operator*(double n, const Stonewt &st)
{
    return Stonewt(n * st.pounds, st.mode); //调用非友元函数进行乘法操作;
}

std::ostream &operator<<(std::ostream &os, const Stonewt &st)
{
    if (st.mode == Stonewt::STONE)
    {
        os << st.stone << " stone, " << st.pds_left << " pounds" << endl;
    }
    else if (st.mode == Stonewt::INT_POUND)
    {
        os << st.pounds_int << " pounds(int)" << endl;
    }
    else if (st.mode == Stonewt::DOUBLE_POUND)
    {
        os << st.pounds << " pounds(double)" << endl;
    }
    else
    {
        os << "Incorrect mode!" << endl;
    }
    return os;
}
