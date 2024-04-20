#include <iostream>
#include <cstdlib>
#include "personmi.h"
using namespace std;

Person::~Person()
{
}

void Person::Data() const
{
    cout << "First name: " << firstname << endl;
    cout << "Last name: " << lastname << endl;
}

void Person::Get()
{
    cout << "Please enter your first name: ";
    getline(cin, firstname);
    cout << "Please enter your last name: ";
    getline(cin, lastname);
}

void Gunslinger::Data() const
{
    cout << "Gunslinger nicks: " << nicks << endl;
}

void Gunslinger::Get()
{
    cout << "Please enter the nicks for gunslinger: ";
    cin >> nicks;
    while (cin.get() != '\n')
        continue;
}

void Gunslinger::Set()
{
    cout << "Enter Gunslinger name" << endl;
    Person::Get();
    Get();
}

void Gunslinger::Show() const
{
    cout << "Category: Gunslinger" << endl;
    Person::Data();
    Data();
}

double Gunslinger::Draw() const
{
    return double(rand() % 5 + 1); //枪手的拔枪时间设置为1到5之间的值;
}

void PokerPlayer::Data() const
{
    cout << "The cards: " << Draw() << endl;
}

void PokerPlayer::Set()
{
    cout << "Enter PokerPlayer name" << endl;
    Person::Get();
}

void PokerPlayer::Show() const
{
    cout << "Category: PokerPlayer" << endl;
    Person::Data();
    Data();
}

int PokerPlayer::Draw() const //扑克牌的值;
{
    return rand() % 52 + 1;
}

void BadDude::Data() const
{
    Gunslinger::Data();
    PokerPlayer::Data();
    cout << "The time for a bad guy to draw his gun is " << Gdraw() << endl;
    cout << "The next card is " << Cdraw() << endl;
}

void BadDude::Get()
{
    Gunslinger::Get();
}

void BadDude::Set()
{
    cout << "Enter BadDude name" << endl;
    Person::Get();
    Get();
}

void BadDude::Show() const
{
    cout << "Category: BadDude" << endl;
    Person::Data();
    Data();
}

double BadDude::Gdraw() const
{
    return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
    return PokerPlayer::Draw();
}
