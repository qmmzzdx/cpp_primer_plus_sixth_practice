#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    ofstream fout;

    fout.open("temp.txt");
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
        {
            break;
        }
        fout << "Target Distance: " << target;
        fout << ", Step Size: " << dstep << endl;
        fout << "0: " << result << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            fout << steps << ": " << result << endl;
        }
        fout << "After " << steps << " steps, the subject ";
        fout << "has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << " or\n";
        fout << result << endl;
        fout << "Average outward distance per step = ";
        fout << result.magval() / steps << endl;
        fout << endl;

        cout << "After " << steps << " steps, the subject ";
        cout << "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n";
        cout << result << endl;
        cout << "Average outward distance per step = ";
        cout << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cin.clear();
    while (cin.get() != '\n')
        continue;
    fout.close();
    cout << "Bye!\n";

    return 0;
}
