#include <iostream>
#include "sales.h"

int main()
{
    SALES::Sales objects[2];
    const double temp[4] = {1.0, 2.0, 3.0, 4.0};

    SALES::setSales(objects[0]);
    SALES::setSales(objects[1], temp, 4);
    SALES::showSales(objects[0]);
    SALES::showSales(objects[1]);
    std::cout << "Bye." << std::endl;

    return 0;
}
