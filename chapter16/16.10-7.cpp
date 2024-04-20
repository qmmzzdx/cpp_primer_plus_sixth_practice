#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

vector<int> Lotto(int dot_len, int random_choice);

int main()
{
    vector<int> winners;
    int dot_len, random_choice;

    cout << "Please enter two numbers" << endl;
    cout << "First for the number of dots on the lottery card and the number" << endl;
    cout << "Second for the number of dots randomly selected (q to quit): ";
    while (cin >> dot_len >> random_choice && random_choice <= dot_len)
    {
        winners = Lotto(dot_len, random_choice);
        cout << "There are " << dot_len << " spots on the lottery card." << endl;
        cout << "Here are the randomly selected " << random_choice << " lottery dots numbers:" << endl;
        copy(winners.begin(), winners.end(), ostream_iterator<int, char>(cout, " "));
        cout << "\nYou can enter two numbers again (q to quit): ";
    }
    cout << "Done." << endl;

    return 0;
}

vector<int> Lotto(int dot_len, int random_choice)
{
    vector<int> temp(dot_len);
    vector<int> num(random_choice);

    for (int i = 0; i < dot_len; i++)
    {
        temp[i] = i + 1;
    }
    random_shuffle(temp.begin(), temp.end());
    num.assign(temp.begin(), temp.begin() + random_choice);
    return num;
}
