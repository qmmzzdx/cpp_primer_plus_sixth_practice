#include <iostream>
#include <cstdlib>
#include "emp.h"
using namespace std;
const int MAX = 10;
const char *emp_str[4] = {"Employee", "Manager", "Fink", "Highfink"};

int main()
{
    char ch;
    abstr_emp *pc[MAX];
    ifstream fin("test.txt");
    if (fin.is_open())
    {
        cout << "Here are the current contents of the test.txt file:";
        int classtype;
        int i = 0;
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case Employee:
            {
                pc[i] = new employee;
                break;
            }
            case Manager:
            {
                pc[i] = new manager;
                break;
            }
            case Fink:
            {
                pc[i] = new fink;
                break;
            }
            case Highfink:
            {
                pc[i] = new highfink;
                break;
            }
            }
            cout << endl;
            cout << emp_str[classtype] << endl;
            pc[i]->getall(fin);
            pc[i++]->ShowAll();
        }
    }
    fin.close();
    ofstream fout("test.txt", ios_base::out | ios_base::app);
    if (!fout.is_open())
    {
        cerr << "Can't open the file test.txt.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter the employee category:\n";
    cout << "e: employee\n";
    cout << "m: manager\n";
    cout << "f: fink\n";
    cout << "h: highfink\n";
    cout << "q: quit\n";
    int i = 0, index = 0;
    while (cin.get(ch).get() && ch != 'q' && index < MAX)
    {
        switch (ch)
        {
            case 'E':
            case 'e':
            {
                pc[index] = new employee;
                pc[index++]->SetAll();
                break;
            }
            case 'M':
            case 'm':
            {
                pc[index] = new manager;
                pc[index++]->SetAll();
                break;
            }
            case 'F':
            case 'f':
            {
                pc[index] = new fink;
                pc[index++]->SetAll();
                break;
            }
            case 'H':
            case 'h':
            {
                pc[index] = new highfink;
                pc[index++]->SetAll();
                break;
            }
            default:
            {
                cout << "Try again: ";
                break;
            }
        }
        cout << "Enter the employee category:\n";
        cout << "e: employee\n";
        cout << "m: manager\n";
        cout << "f: fink\n";
        cout << "h: highfink\n";
        cout << "q: quit\n";
    }
    for (i = 0; i < index; ++i)
    {
        pc[i]->writeall(fout);
    }
    fout.close();
    cout << "Done.\n";

    return 0;
}
