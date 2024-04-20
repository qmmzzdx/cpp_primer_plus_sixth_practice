#include <iostream>
#include "stock20.h"
using namespace std;
#include <cstring>

Stock::Stock()
{
    company = new char[1];
    company[0] = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *s, long n, double pr)
{
    company = new char[strlen(s) + 1];
    std::strcpy(company, s);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; ";
        std::cout << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    delete[] company;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. ";
        std::cout << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. ";
        cout << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! ";
        cout << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream &operator<<(std::ostream &os, const Stock &st)
{
    os << "Company: " << st.company << std::endl;
    os << "Shares: " << st.shares << std::endl;
    os << "Share Price: " << st.share_val << std::endl;
    os << "Total Worth: " << st.total_val << std::endl;
    return os;
}

const Stock &Stock::topval(const Stock &s) const
{
    return s.total_val > total_val ? s : *this;
}
