#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);
    auto lambda_outint = [](int n)
    { cout << n << " "; };

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), lambda_outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), lambda_outint);
    cout << endl;
    yadayada.remove_if([](int n)
                       { return n > 100; });
    etcetera.remove_if([](int n)
                       { return n > 200; });
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), lambda_outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), lambda_outint);
    cout << endl;

    return 0;
}
