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
    CandyBar snack{"Mocha Munch", 2.3, 350};

    cout << "Brand : " << snack.brand << endl;
    cout << "Candy_weight: " << snack.candy_weight << endl;
    cout << "Candy_calorie: " << snack.candy_calorie << endl;

    return 0;
}
