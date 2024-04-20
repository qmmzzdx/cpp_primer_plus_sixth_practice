#include <iostream>
#include "golf.h"

int main()
{
    using std::cout;
    using std::endl;

    Golf temp1;
    Golf temp2("MZZDX", 666);

    cout << "The starting information1:" << endl;
    temp1.showgolf();
    temp1.set_handicap(998);
    cout << "After changing the handicap1:" << endl;
    temp1.showgolf();
    cout << "The starting information2:" << endl;
    temp2.showgolf();
    temp2.set_handicap(888);
    cout << "After changing the handicap2:" << endl;
    temp2.showgolf();

    return 0;
}
