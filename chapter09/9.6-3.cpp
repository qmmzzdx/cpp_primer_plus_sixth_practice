#include <iostream>
#include <cstring>
#include <new>

const int BUF = 512;
static char buffer[BUF];
struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;
    char temp[20];
    chaff *str = new (buffer) chaff[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the content of dross #" << i + 1 << ": ";
        cin.getline(temp, 20);
        strcpy(str[i].dross, temp);
        cout << "Enter the content of slag #" << i + 1 << ": ";
        while (!(cin >> str[i].slag))
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
    for (int i = 0; i < 2; i++)
    {
        cout << "Chaff #" << i + 1 << ": " << endl;
        cout << "Dross: " << str[i].dross << endl;
        cout << "Slag: " << str[i].slag << endl;
    }

    return 0;
}
