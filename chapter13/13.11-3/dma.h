#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA
{
private:
    char *classname; //基类成员设为一个char指针方便分配内存空间保存派生类的类名;

protected:
    const char *show_classname() const { return classname; } //抽象基类DMA的View方法不进行定义因此使用protected让派生类可以访问基类数据;

public:
    DMA(const char *cn = "null");  //声明基类DMA的默认构造函数;
    DMA(const DMA &rs);            //声明基类DMA的复制构造函数;
    DMA &operator=(const DMA &rs); //声明为基类DMA重载赋值运算符;
    virtual ~DMA();                //声明基类DMA的虚析构函数;
    virtual void View() const = 0; //声明基类DMA的纯虚函数;
};

class baseDMA : public DMA
{
private:
    char *label;
    int rating;

public:
    baseDMA(const char *l = "null", int r = 0, const char *cn = "null"); //声明派生类baseDMA的默认构造函数;
    baseDMA(const char *l, int r, const DMA &rs);                        //声明派生类baseDMA的用户定义构造函数;
    baseDMA(const baseDMA &rs);                                          //声明派生类baseDMA的复制构造函数;
    ~baseDMA();                                                          //声明派生类baseDMA的析构函数;
    baseDMA &operator=(const baseDMA &rs);                               //声明为派生类baseDMA重载赋值运算符;
    virtual void View() const;                                           //声明为派生类baseDMA定义基类虚函数;
};

class lacksDMA : public DMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];

public:
    lacksDMA(const char *c = "blank", const char *cn = "null"); //声明派生类lacksDMA的默认构造函数;
    lacksDMA(const char *c, const DMA &rs);                     //声明派生类lacksDMA的用户定义构造函数;
    lacksDMA(const lacksDMA &rs);                               //声明派生类lacksDMA的复制构造函数;
    ~lacksDMA();                                                //声明派生类lacksDMA的析构函数;
    lacksDMA &operator=(const lacksDMA &rs);                    //声明为派生类lacksDMA重载赋值运算符;
    virtual void View() const;                                  //声明为派生类lacksDMA定义基类虚函数;
};

class hasDMA : public DMA
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *cn = "null"); //声明派生类hasDMA的默认构造函数;
    hasDMA(const char *s, const DMA &rs);                    //声明派生类hasDMA的用户定义构造函数;
    hasDMA(const hasDMA &rs);                                //声明派生类hasDMA的复制构造函数;
    ~hasDMA();                                               //声明派生类hasDMA的析构函数;
    hasDMA &operator=(const hasDMA &rs);                     //声明为派生类hasDMA重载赋值运算符;
    virtual void View() const;                               //声明为派生类hasDMA定义基类虚函数;
};

#endif
