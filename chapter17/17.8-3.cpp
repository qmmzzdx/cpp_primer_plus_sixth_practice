#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Your command arguments are invalid!" << endl;
        exit(EXIT_FAILURE);
    }
    char ch;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fin.is_open())
    {
        cerr << "Can't open the file " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
        cerr << "Can't open the file " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    while ((ch = fin.get()) != EOF)
    {
        fout.put(ch);
    }
    cout << "Done.\n";
    fin.close();
    fout.close();

    return 0;
}
