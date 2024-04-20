#include <iostream>

const int Seasons = 4;
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct spending
{
    double expenses[Seasons];
};

void fill(spending *temp);
void show(spending *temp);

int main()
{
    spending temp;
    fill(&temp);
    show(&temp);

    return 0;
}

void fill(spending *temp)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> temp->expenses[i];
    }
}

void show(spending *temp)
{
    double total = 0.0;

    std::cout << "EXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << temp->expenses[i] << '\n';
        total += temp->expenses[i];
    }
    std::cout << "Total: $" << total << '\n';
}
