#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    return false;
}

void Tv::chanup()
{
    channel = channel < maxchannel ? 1 + channel : 1;
}

void Tv::chandown()
{
    channel = channel > 1 ? channel - 1 : maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = ";
        cout << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = ";
        cout << (input == TV ? "TV" : "DVD") << endl;
    }
}
