#include <iostream>
#include <string>
using namespace std;

struct Pizza
{
    string pizza_company;
    double pizza_diameter;
    double pizza_weight;
};

int main()
{
    Pizza *snack = new Pizza;

    cout << "Please enter the diameter of the pizza: ";
    (cin >> snack->pizza_diameter).get();
    cout << "Please enter the name of the Pizza Company: ";
    getline(cin, snack->pizza_company);
    cout << "Please enter the weight of the pizza: ";
    cin >> snack->pizza_weight;

    cout << "The name of the Pizza Company: " << snack->pizza_company << endl;
    cout << "The diameter of the Pizza Company: " << snack->pizza_diameter << endl;
    cout << "The weight of the Pizza Company: " << snack->pizza_weight << endl;
    delete snack;

    return 0;
}
