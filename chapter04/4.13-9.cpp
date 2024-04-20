#include <iostream>
#include <string>
using namespace std;

struct CandyBar
{
    string brand;
    double candy_weight;
    int candy_calorie;
};

int main()
{
    CandyBar *snack = new CandyBar[3];

    snack[0] = {"Mocha Munch", 2.3, 350};
    snack[1] = {"Mooncake", 3.5, 369};
    snack[2] = {"Birthdaycake", 6.8, 460};

    cout << "The first candy:" << endl;
    cout << "Brand: " << snack[0].brand << endl;
    cout << "Candy_weight: " << snack[0].candy_weight << endl;
    cout << "Candy_calorie: " << snack[0].candy_calorie << endl;

    cout << "\nThe second candy:" << endl;
    cout << "Brand: " << snack[1].brand << endl;
    cout << "Candy_weight: " << snack[1].candy_weight << endl;
    cout << "Candy_calorie: " << snack[1].candy_calorie << endl;

    cout << "\nThe third candy:" << endl;
    cout << "Brand: " << snack[2].brand << endl;
    cout << "Candy_weight: " << snack[2].candy_weight << endl;
    cout << "Candy_calorie: " << snack[2].candy_calorie << endl;
    delete[] snack;

    return 0;
}
