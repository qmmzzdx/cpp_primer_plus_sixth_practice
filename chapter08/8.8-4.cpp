#include <iostream>
#include <cstring>
using namespace std;

struct stringy
{
    char *str;
    int ct;
};

void set(stringy &stry, const char *str);
void show(const stringy &stry, int n = 1);
void show(const char *str, int n = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    delete[] beany.str;
    show("Done!");

    return 0;
}

void set(stringy &stry, const char *str)
{
    stry.str = new char[strlen(str) + 1];
    strcpy(stry.str, str);
    return;
}

void show(const stringy &stry, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << stry.str << endl;
    }
}

void show(const char *str, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << str << endl;
    }
}
