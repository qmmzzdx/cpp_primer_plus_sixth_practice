#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};

void initialize_candybar(CandyBar &temp, const char *str = "Millennium Munch", double w = 2.85, int c = 350);
void show_candybar(const CandyBar &temp);

int main()
{
    CandyBar mycandybar;

    initialize_candybar(mycandybar);
    show_candybar(mycandybar);

    return 0;
}

void initialize_candybar(CandyBar &temp, const char *str, double w, int c)
{
    strcpy(temp.brand, str);
    temp.weight = w;
    temp.calorie = c;
}

void show_candybar(const CandyBar &temp)
{
    cout << "CandyBar information:" << endl;
    cout << "Brand: " << temp.brand << endl;
    cout << "Weight: " << temp.weight << endl;
    cout << "Calorie: " << temp.calorie << endl;
}
