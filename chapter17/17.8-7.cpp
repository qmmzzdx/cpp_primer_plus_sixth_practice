#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Store
{
private:
    ofstream &fout;

public:
    Store(ofstream &os) : fout(os) {}
    void operator()(const string &s)
    {
        auto len = s.size();
        fout.write((char *)&len, sizeof(size_t));
        fout.write(s.data(), len);
    }
};

void ShowStr(const string &s);
void GetStrs(ifstream &is, vector<string> &s);

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
    {
        vostr.push_back(temp);
    }
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Coult not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const string &s)
{
    cout << s << endl;
}

void GetStrs(ifstream &is, vector<string> &s)
{
    char *tmp;
    size_t len;
    while (is.read((char *)&len, sizeof(size_t)))
    {
        tmp = new char[len + 1];
        is.read(tmp, len);
        tmp[len] = '\0';
        s.push_back(tmp);
    }
}
