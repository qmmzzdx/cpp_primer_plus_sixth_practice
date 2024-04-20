#include <iostream>
using namespace std;

void show_menu();

int main()
{
    char ch;

    show_menu();
    while (cin >> ch)
    {
        switch (ch)
        {
            case 'c':
            {
                cout << "Pandas are also carnivores." << endl;
                break;
            }
            case 'p':
            {
                cout << "Mozart is an excellent pianist." << endl;
                break;
            }
            case 't':
            {
                cout << "A maple is a tree." << endl;
                break;
            }
            case 'g':
            {
                cout << "Playing game can relax yourself." << endl;
                break;
            }
            default:
            {
                cout << "Please enter a c, p, t, or g: ";
                break;
            }
        }
        if ('c' == ch || 'p' == ch || 't' == ch || 'g' == ch)
        {
            break;
        }
    }

    return 0;
}

void show_menu()
{
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore p) pianist" << endl;
    cout << "t) tree g) game" << endl;
}
