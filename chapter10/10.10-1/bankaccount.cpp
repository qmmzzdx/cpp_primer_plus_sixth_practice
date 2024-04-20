#include <iostream>
#include <string>
#include "bankaccount.h"

BankAccount::BankAccount() //默认构造函数;
{
    name = "no name";
    acctnum = "no acctnum";
    balance = 0.0;
}

BankAccount::BankAccount(const std::string &client, const std::string &num, double bal) //用户构造函数;
{
    name = client;
    acctnum = num;
    balance = bal;
}

void BankAccount::show() const
{
    using std::cout;
    using std::endl;

    cout << "Name: " << name << endl;
    cout << "Acctnum: " << acctnum << endl;
    cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double cash)
{
    using std::cout;
    using std::endl;

    if (cash <= 0) //存款数额不能小于0;
    {
        cout << "Your deposit amount can't be less than 0!" << endl;
        return;
    }
    balance += cash;
    cout << "You deposit $" << cash << " successfully." << endl;
}

void BankAccount::withdraw(double cash)
{
    using std::cout;
    using std::endl;

    if (balance < cash) //取款数大于当前账户金额时的情况;
    {
        cout << "You can't withdraw more than your deposit!" << endl;
        return;
    }
    else if (cash <= 0) //取款数小于等于0时的情况;
    {
        cout << "Your withdrawal amount can't be less than 0!" << endl;
        return;
    }
    balance -= cash;
    cout << "You withdraw $" << cash << " successfully." << endl;
}
