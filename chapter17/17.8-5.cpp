#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    string name;
    set<string> mat_friends;
    set<string> pat_friends;
    ifstream fin1("mat.dat");
    ifstream fin2("pat.dat");
    ofstream fout("matnpat.dat");
    ostream_iterator<string> out1(cout, "\n");
    ostream_iterator<string> out2(fout, "\n");

    if (!fin1.is_open())
    {
        cerr << "Can't open the file mat.dat\n";
        exit(EXIT_FAILURE);
    }
    if (!fin2.is_open())
    {
        cerr << "Can't open the file pat.dat\n";
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cerr << "Can't open the file matnpat.dat\n";
        exit(EXIT_FAILURE);
    }
    while (getline(fin1, name))
    {
        mat_friends.insert(name);
    }
    while (getline(fin2, name))
    {
        pat_friends.insert(name);
    }
    cout << "Here are the Mat's friends:" << endl;
    copy(mat_friends.begin(), mat_friends.end(), out1);

    cout << "Here are the Pat's friends:" << endl;
    copy(pat_friends.begin(), pat_friends.end(), out1);

    set_union(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(), out2);
    cout << "\nDone.\n";
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}
