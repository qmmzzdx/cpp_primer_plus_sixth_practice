#include <iostream>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void value_show_box(box temp);
void address_show_box(box *temp);

int main()
{
    box smallbox = {"Cute box", 20, 10, 30, 50};

    value_show_box(smallbox);
    address_show_box(&smallbox);
    value_show_box(smallbox);

    return 0;
}

void value_show_box(box temp)
{
    cout << "Box informations: " << endl;
    cout << "Name: " << temp.maker << endl;
    cout << "height: " << temp.height << endl;
    cout << "width: " << temp.width << endl;
    cout << "length: " << temp.length << endl;
    cout << "volume: " << temp.volume << endl;
}

void address_show_box(box *temp)
{
    temp->volume = temp->height * temp->width * temp->length;
}
