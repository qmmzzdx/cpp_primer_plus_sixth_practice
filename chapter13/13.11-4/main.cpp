#include "port.h"
#include "vintageport.h"

int main()
{
    Port wine1("Gallo", "tawny", 20);                     //构造Port基类对象;
    VintagePort wine2("Lafei", 10, "strong wine", 1876);  //构造VintagePort基类对象;
    VintagePort wine3("Merlot", 50, "middle wine", 1976); //构造VintagePort基类对象;

    cout << "Here is the Port object:\n";
    wine1.Show();          //调用基类Show方法;
    cout << wine1 << endl; //调用基类重载输出流运算符;

    cout << "\nHere are the VintagePort objects:\n";
    wine2.Show();          //调用派生类Show方法;
    cout << wine2 << endl; //调用派生类重载输出流运算符;
    wine3.Show();          //调用派生类Show方法;
    cout << wine3 << endl; //调用派生类重载输出流运算符;

    cout << "\nGallo add 20 bottles:\n";
    wine1 += 20; //调用基类重载+=运算符;
    wine1.Show();

    cout << "\nLafei add 10 bottles:\n";
    wine2 += 10; //调用派生类重载+=运算符;
    wine2.Show();

    cout << "\nMerlot minus 10 bottles:\n";
    wine3 -= 10; //调用派生类重载-=运算符;
    wine3.Show();

    VintagePort wine4(wine2); //调用派生类复制构造函数;
    cout << "\nResult of VintagePort copy:\n";
    wine4.Show();

    VintagePort wine5;
    wine5 = wine3; //调用派生类重载赋值运算符;
    cout << "\nResult of VintagePort assignment:\n";
    wine5.Show();

    return 0;
}
