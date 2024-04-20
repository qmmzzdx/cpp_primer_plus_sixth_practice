#include <iostream>
#include "cow.h"

int main()
{
    using std::cout;
    using std::endl;

    Cow temp1;
    Cow temp2("MZZDX", "Programming", 30);
    Cow temp3(temp2);

    cout << "Here are some cows:" << endl;
    cout << "The first:" << endl;
    temp1.ShowCow();
    cout << "The second:" << endl;
    temp2.ShowCow();
    cout << "The third:" << endl;
    temp3.ShowCow();
    temp1 = temp3;
    cout << "After assignment for temp1:" << endl;
    temp1.ShowCow();

    return 0;
}
