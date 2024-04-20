#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    double temp[4] = {1.0, 2.0, 3.0, 4.0};
    Sales objects[2] = {Sales(temp, 4), Sales()}; //首元素默认初始化,次元素用户初始化;

    std::cout << "The first object information:" << std::endl;
    objects[0].show_sales();
    std::cout << "The second object information:" << std::endl;
    objects[1].show_sales();
    std::cout << "Bye." << std::endl;

    return 0;
}
