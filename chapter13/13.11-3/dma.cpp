#include "dma.h"
#include <cstring>

DMA::DMA(const char *cn) //定义基类DMA的默认构造函数;
{
    classname = new char[std::strlen(cn) + 1];
    std::strcpy(classname, cn);
}

DMA::DMA(const DMA &rs) //定义基类DMA的复制构造函数;
{
    classname = new char[std::strlen(rs.classname) + 1];
    std::strcpy(classname, rs.classname);
}

DMA &DMA::operator=(const DMA &rs) //为基类DMA重载赋值运算符;
{
    if (this == &rs)
    {
        return *this;
    }
    delete[] classname; //先释放后分配;
    classname = new char[std::strlen(rs.classname) + 1];
    std::strcpy(classname, rs.classname);
    return *this;
}

DMA::~DMA() //定义基类DMA的析构函数;
{
    delete[] classname;
}

baseDMA::baseDMA(const char *l, int r, const char *cn) : DMA(cn) //定义派生类baseDMA的默认构造函数;
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const char *l, int r, const DMA &rs) : DMA(rs) //定义派生类baseDMA的用户定义构造函数;
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) : DMA(rs) //定义派生类baseDMA的复制构造函数;
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA() //定义派生类baseDMA的析构函数;
{
    delete[] label;
}

baseDMA &baseDMA::operator=(const baseDMA &rs) //为派生类baseDMA重载赋值运算符;
{
    if (this == &rs)
    {
        return *this;
    }
    delete[] label;     //先释放后分配;
    DMA::operator=(rs); //调用基类DMA的赋值运算符方法初始化派生类baseDMA的基类数据成员;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

void baseDMA::View() const //为派生类baseDMA定义基类虚函数;
{
    std::cout << "Classname: " << show_classname() << std::endl; //调用基类protected中的show_classname方法显示基类数据成员;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

lacksDMA::lacksDMA(const char *c, const char *cn) : DMA(cn) //定义派生类lacksDMA的默认构造函数;
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const DMA &rs) : DMA(rs) //定义派生类lacksDMA的用户定义构造函数;
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA &rs) : DMA(rs) //定义派生类lacksDMA的复制构造函数;
{
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::~lacksDMA()
{
}

lacksDMA &lacksDMA::operator=(const lacksDMA &rs) //为派生类lacksDMA重载赋值运算符;
{
    if (this == &rs)
    {
        return *this;
    }
    DMA::operator=(rs); //调用基类DMA的赋值运算符方法初始化派生类lacksDMA的基类数据成员;
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
    return *this;
}

void lacksDMA::View() const //为派生类lacksDMA定义基类虚函数;
{
    std::cout << "Classname: " << show_classname() << std::endl; //调用基类protected中的show_classname方法显示基类数据成员;
    std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char *s, const char *cn) : DMA(cn) //定义派生类hasDMA的默认构造函数;
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const DMA &rs) : DMA(rs) //定义派生类hasDMA的用户定义构造函数;
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &rs) : DMA(rs) //定义派生类hasDMA的复制构造函数;
{
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
}

hasDMA::~hasDMA() //定义派生类hasDMA的析构函数;
{
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &rs) //为派生类hasDMA重载赋值运算符;
{
    if (this == &rs)
    {
        return *this;
    }
    delete[] style;     //先释放后分配;
    DMA::operator=(rs); //调用基类DMA的赋值运算符方法初始化派生类hasDMA的基类数据成员;
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
    return *this;
}

void hasDMA::View() const //为派生类hasDMA定义基类虚函数;
{
    std::cout << "Classname: " << show_classname() << std::endl; //调用基类protected中的show_classname方法显示基类数据成员;
    std::cout << "Style: " << style << std::endl;
}
