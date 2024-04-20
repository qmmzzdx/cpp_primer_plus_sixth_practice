/*
新建2个txt文件为in1.txt和in2.txt
in1.txt内容:
eggs kites donuts
balloons hammers
stones
in2.txt内容:
zero lassitude
finance drama
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    vector<string> ans1;
    vector<string> ans2;
    ifstream fin1("in1.txt");
    ifstream fin2("in2.txt");
    ofstream fout("out.txt");
    if (!fin1.is_open())
    {
        cout << "Can't open the file in1.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!fin2.is_open())
    {
        cout << "Can't open the file in2.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cout << "Can't open the file out.txt\n";
        exit(EXIT_FAILURE);
    }
    while (getline(fin1, s))
    {
        ans1.push_back(s);
    }
    while (getline(fin2, s))
    {
        ans2.push_back(s);
    }
    for (int i = 0; i < ans1.size() || i < ans2.size(); ++i)
    {
        if (i >= ans1.size())
        {
            fout << ans2[i] << endl;
        }
        else if (i >= ans2.size())
        {
            fout << ans1[i] << endl;
        }
        else
        {
            fout << ans1[i] << ' ' << ans2[i] << endl;
        }
    }
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}
