#include "port.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[std::strlen(br) + 1]; //new分配内存;
    std::strcpy(brand, br);
    std::strncpy(style, st, 20);
    style[19] = '\0'; //保证字符串是有效的;
    bottles = b;
}

Port::Port(const Port &p)
{
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strncpy(style, p.style, 20);
    style[19] = '\0';
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if (this == &p)
    {
        return *this;
    }
    delete[] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strncpy(style, p.style, 20);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}

Port &Port::operator+=(int b)
{
    bottles += b;
    return *this; //返回调用对象的引用;
}

Port &Port::operator-=(int b)
{
    bottles -= b;
    return *this; //返回调用对象的引用;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
