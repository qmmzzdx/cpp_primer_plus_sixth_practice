#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
public:
    enum Mode { STONE, INT_POUND, DOUBLE_POUND };

private:
    enum { Lbs_per_stn = 14 }; //1英石等于14英镑;
    int stone;
    double pds_left;
    double pounds;
    int pounds_int;
    Mode mode;
    void set_stone();      //设置stone英石变量;
    void set_pounds();     //设置pounds英镑变量;
    void set_pounds_int(); //设置pounds整型英镑变量;

public:
    Stonewt(double lbs, Mode form);
    Stonewt(int stn, double lbs, Mode form);
    Stonewt();
    ~Stonewt();
    void set_stone_mode();                                 //设置英石格式;
    void set_pounds_mode();                                //设置整数磅格式;
    void set_int_pounds_mode();                            //设置浮点磅格式;
    Stonewt operator+(const Stonewt &st) const;            //重载'+'运算符;
    Stonewt operator-(const Stonewt &st) const;            //重载'-'运算符;
    Stonewt operator*(double n) const;                     //重载'*'运算符;
    friend Stonewt operator*(double n, const Stonewt &st); //友元函数重载'*'运算符可以令对象在'*'右边进行操作;
    friend std::ostream &operator<<(std::ostream &os, const Stonewt &st);
};

#endif
