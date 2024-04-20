#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Your command arguments are invalid!" << endl;
        exit(EXIT_FAILURE);
    }
    char ch;
    ofstream fout(argv[1]);
    if (!fout.is_open())
    {
        cerr << "Can't open the file " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Please enter some characters: ";
    while ((ch = cin.get()) != EOF)
    {
        fout << ch;
    }
    cout << "Done.\n";
    fout.close();

    return 0;
}
