#include <iostream>
#include <string>
using namespace std;

const int HIGH_MONEY = 10000;

struct corporation
{
    string name;
    double money;
};

int main()
{
    int i, num;
    unsigned int patrons = 0;
    unsigned int grand_patrons = 0;

    cout << "Please enter the number of donators: ";
    (cin >> num).get();
    corporation *people = new corporation[num];

    for (i = 0; i < num; i++)
    {
        cout << "Please enter name #" << i + 1 << ": ";
        getline(cin, people[i].name);
        cout << "Please enter the amount of donation #" << i + 1 << ": ";
        while (!(cin >> people[i].money))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Please enter a number: ";
        }
        cin.get();
    }
    for (i = 0; i < num; i++)
    {
        (HIGH_MONEY < people[i].money) ? ++grand_patrons : ++patrons;
    }

    cout << "\nGrand Patrons:" << endl;
    if (grand_patrons != 0)
    {
        for (i = 0; i < num; i++)
        {
            if (people[i].money > HIGH_MONEY)
            {
                cout << "Name: " << people[i].name;
                cout << "\nMoney: " << people[i].money << endl;
            }
        }
    }
    else
    {
        cout << "none" << endl;
    }
    cout << "\nPatrons:" << endl;
    if (patrons != 0)
    {
        for (i = 0; i < num; i++)
        {
            if (people[i].money < HIGH_MONEY)
            {
                cout << "Name: " << people[i].name;
                cout << "\nMoney: " << people[i].money << endl;
            }
        }
    }
    else
    {
        cout << "none" << endl;
    }
    delete[] people;

    return 0;
}
