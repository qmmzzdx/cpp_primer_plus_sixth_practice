#include <iostream>
#include <cstring>
#include "personmi.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    int i, ct;
    Person *people[SIZE];

    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the person category:" << endl;
        cout << "g: gunslinger" << endl;
        cout << "p: pokerplayer" << endl;
        cout << "b: baddude" << endl;
        cout << "q: quit" << endl;
        cin >> choice;
        while (NULL == strchr("bgpq", choice))
        {
            cout << "Please enter b, g, p or q: ";
            cin >> choice;
        }
        if ('q' == choice)
        {
            break;
        }
        switch (choice)
        {
            case 'b':
            {
                people[ct] = new BadDude;
                break;
            }
            case 'g':
            {
                people[ct] = new Gunslinger;
                break;
            }
            case 'p':
            {
                people[ct] = new PokerPlayer;
                break;
            }
        }
        cin.get();
        people[ct]->Set();
    }
    cout << "\nHere is your message for some people:" << endl;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        people[i]->Show();
    }
    for (i = 0; i < ct; i++)
    {
        delete people[i];
    }
    cout << "Bye.\n";

    return 0;
}
