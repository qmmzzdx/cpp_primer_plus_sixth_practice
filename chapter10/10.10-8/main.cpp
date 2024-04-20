#include <iostream>
#include <cctype>
#include "list.h"

void traverse(Item &item);

int main()
{
    using namespace std;
    char ch;
    Item temp;
    List mylist;

    cout << "The list include following functions:" << endl;
    cout << "a to add an number." << endl;
    cout << "v to visit every number." << endl;
    cout << "q to exit the menu." << endl;
    cout << "Please enter your choice: ";
    while (cin >> ch && tolower(ch) != 'q')
    {
        while (cin.get() != '\n')
            continue;
        if (tolower(ch) != 'a' && tolower(ch) != 'v')
        {
            cout << "Please enter a, v or q: ";
            continue;
        }
        switch (tolower(ch))
        {
            case 'a':
            {
                cout << "Please enter an number: ";
                while (!(cin >> temp))
                {
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    cout << "Please enter an number again: ";
                }
                if (mylist.is_full())
                {
                    cout << "The list is full. Can't add new number." << endl;
                }
                else
                {
                    mylist.add_data(temp);
                    cout << "Add number " << temp << " successfully." << endl;
                }
                break;
            }
            case 'v':
            {
                if (mylist.is_empty())
                {
                    cout << "No number.\n";
                }
                else
                {
                    cout << "Visit every number:" << endl;
                    mylist.visit(traverse);
                }
                break;
            }
        }
        cout << "\n\n\n";
        cout << "The list include following functions:" << endl;
        cout << "a to add an number." << endl;
        cout << "v to visit every number." << endl;
        cout << "q to exit the menu." << endl;
        cout << "Please enter your choice: ";
    }
    cout << "Bye." << endl;

    return 0;
}

void traverse(Item &item)
{
    std::cout << item << ' ';
}
