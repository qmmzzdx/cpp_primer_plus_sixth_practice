#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    char ch;
    ifstream infile;
    string filename;
    unsigned int count = 0;

    cout << "Please enter name of data file: ";
    getline(cin, filename);
    infile.open(filename);

    if (!infile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    while (infile.get(ch), infile.good())
    {
        ++count;
        cout.put(ch);
    }
    if (count > 0)
    {
        cout << count << " characters in the file " << filename << endl;
    }
    else
    {
        cout << "No data processed." << endl;
    }
    infile.close();

    return 0;
}
