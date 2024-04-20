#include <iostream>
#include "move.h"

int main()
{
    using std::cout;
    using std::endl;
    Move temp;

    cout << "Starting values:" << endl;
    temp.showmove();
    cout << "After x + 2, y + 5:" << endl;
    temp.reset(2, 5);
    temp.showmove();
    cout << "After adding new object value:" << endl;
    temp = temp.add(temp);
    temp.showmove();

    return 0;
}
