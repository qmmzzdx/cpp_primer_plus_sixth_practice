#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
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
    string filename;
    ifstream infile;
    unsigned int patrons = 0;
    unsigned int grand_patrons = 0;

    cout << "Please enter name of data file: ";
    getline(cin, filename);
    infile.open(filename);
    if (!infile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }

    (infile >> num).get();
    corporation *people = new corporation[num];
    for (i = 0; i < num && infile.good(); i++)
    {
        getline(infile, people[i].name);
        while (!(infile >> people[i].money))
        {
            infile.clear();
            while (infile.get() != '\n')
            {
                continue;
            }
        }
        while (infile.get() != '\n')
        {
            continue;
        }
    }
    infile.close();

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
