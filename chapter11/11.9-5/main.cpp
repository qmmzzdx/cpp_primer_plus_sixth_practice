#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    using std::endl;
    Stonewt incognito(275, Stonewt::DOUBLE_POUND);
    Stonewt wolfe(285.7, Stonewt::STONE);
    Stonewt taft(21, 8, Stonewt::INT_POUND);

    cout << "Here are the tsets:" << endl;
    cout << "The celebrity weighed ";
    cout << incognito;
    cout << "The detective weighed ";
    cout << wolfe;
    cout << "The President weighed ";
    cout << taft;
    cout << "incognito + wolfe = " << incognito + wolfe;
    cout << "wolfe - incognito = " << wolfe - incognito;
    cout << "taft * 10.0 = " << taft * 10.0;
    cout << "10.0 * taft = " << 10.0 * taft;

    return 0;
}
