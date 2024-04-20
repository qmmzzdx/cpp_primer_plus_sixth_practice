#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;

    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    s42.set_status(grey);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    grey.show_status();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    s58.set_status(grey);
    cout << "\n58\" settings:\n";
    s58.settings();
    grey.show_status();

    return 0;
}
