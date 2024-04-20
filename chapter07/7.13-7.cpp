#include <iostream>
using namespace std;

const int Max = 5;

double *fill_array(double *begin, double *end);
void show_array(const double *begin, double *end);
void revalue(double r, double *begin, double *end);

int main()
{
    double properties[Max];

    double *size = fill_array(properties, properties + Max);
    show_array(properties, size);
    if (size - properties > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";

    return 0;
}

double *fill_array(double *begin, double *end)
{
    int i;
    double temp;
    double *ptr = nullptr;

    for (i = 0, ptr = begin; ptr < end; i++, ptr++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
        {
            break;
        }
        *ptr = temp;
    }
    return begin + i;
}

void show_array(const double *begin, double *end)
{
    int i;
    const double *ptr = nullptr;

    for (i = 0, ptr = begin; ptr < end; i++, ptr++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << *ptr << endl;
    }
}

void revalue(double r, double *begin, double *end)
{
    for (double *pos = begin; pos < end; pos++)
    {
        *pos *= r;
    }
}
