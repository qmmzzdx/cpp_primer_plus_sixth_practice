#include <iostream>
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
    ostream_iterator<string, char> output(cout, "\n");

    cout << "Hello Mat, please enter your friends to invite them to join in the party (q to quit): ";
    while (getline(cin, name), name != "q")
    {
        mat_friends.insert(name);
        cout << "Next name: ";
    }
    cout << "Hello Pat, please enter your friends to invite them to join in the party (q to quit): ";
    while (getline(cin, name), name != "q")
    {
        pat_friends.insert(name);
        cout << "Next name: ";
    }
    cout << "Here are the Mat's friends:" << endl;
    copy(mat_friends.begin(), mat_friends.end(), output);

    cout << "Here are the Pat's friends:" << endl;
    copy(pat_friends.begin(), pat_friends.end(), output);

    cout << "Here are the Mat and Pat friends after merging and removing repetitive values:" << endl;
    set_union(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(), output);
    cout << "Done." << endl;

    return 0;
}
