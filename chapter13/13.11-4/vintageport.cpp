#include <cstring>
#include "port.h"
#include "vintageport.h"

VintagePort::VintagePort() : Port("none", "vintage", 0) //成员列表初始化派生类的基类对象数据;
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b) //成员列表初始化派生类的基类对象数据;
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp) //调用基类复制构造函数初始化派生类的基类对象数据;
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
    {
        return *this;
    }
    delete[] nickname;
    Port::operator=(vp); //调用基类赋值运算符修改派生类的基类数据成员;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp; //强制类型转换调用Port基类的重载输出流运算符方法;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
