#include <iostream>
#include "worker.h"
using std::cin;
using std::cout;
using std::endl;

Worker::~Worker()
{
}

void Worker::Set()
{
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "Worker name: " << fullname << endl;
    cout << "Worker ID: " << id << endl;
}
