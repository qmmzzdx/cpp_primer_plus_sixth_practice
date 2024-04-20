#include <iostream>

const int Seasons = 4;
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double pa[], int n);
void show(const double pa[], int n);

int main()
{
    double expenses[Seasons];
    fill(expenses, Seasons);
    show(expenses, Seasons);

    return 0;
}

void fill(double pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}

void show(const double pa[], int n)
{
    double total = 0.0;

    std::cout << "EXPENSES\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << Snames[i] << ": $" << pa[i] << '\n';
        total += pa[i];
    }
    std::cout << "Total: $" << total << '\n';
}
