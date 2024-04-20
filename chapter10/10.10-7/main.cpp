#include <iostream>
#include "plorg.h"

int main()
{
    using std::cout;
    using std::endl;
    Plorg temp;

    cout << "The starting plorg information:" << endl;
    temp.show_plorg();
    temp.create_new_plorg("MZZDX");
    cout << "\nAfter changing name and ci:" << endl;
    temp.show_plorg();
    temp.reset_ci();
    cout << "\nAfter changing ci:" << endl;
    temp.show_plorg();
    cout << "Bye." << endl;

    return 0;
}
