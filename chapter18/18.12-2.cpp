#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };

private:
    Info *pi;

public:
    Cpmv();
    Cpmv(string q, string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv &&mv);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &cp);
    Cpmv &operator=(Cpmv &&mv);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};

Cpmv::Cpmv()
{
    cout << "Default constructor called.\n";
    pi = new Info;
    pi->qcode = "none";
    pi->zcode = "none";
}

Cpmv::Cpmv(string q, string z)
{
    cout << "String constructor called.\n";
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv &cp)
{
    cout << "Copy constructor called.\n";
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv &&mv)
{
    cout << "Move constructor called.\n";
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    delete pi;
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
    if (this != &cp)
    {
        delete pi;
        pi = new Info;
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
    }
    return *this;
    cout << "Copy assignment operator called.\n";
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
    if (this != &mv)
    {
        delete pi;
        pi = mv.pi;
        mv.pi = nullptr;
    }
    return *this;
    cout << "Move assignment operator called.\n";
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const
{
    if (pi)
    {
        cout << "The qcode is " << pi->qcode << endl;
        cout << "The zcode is " << pi->zcode << endl;
    }
    else
    {
        cout << "Cpmv::pi pointer is nullptr" << endl;
    }
    cout << endl;
}

int main()
{
    Cpmv temp1;
    cout << "temp1:\n";
    temp1.Display();

    Cpmv temp2("mzzdx", "god");
    cout << "temp2:\n";
    temp2.Display();

    Cpmv temp3(temp1);
    cout << "temp3:\n";
    temp3.Display();

    cout << "temp4 = temp1:\n";
    Cpmv temp4;
    temp4 = temp1;
    cout << "temp4:\n";
    temp4.Display();
    cout << "temp1:\n";
    temp1.Display();

    cout << "temp5 = move(temp2):\n";
    Cpmv temp5;
    temp5 = move(temp2);
    cout << "temp5:\n";
    temp5.Display();
    cout << "temp2:\n";
    temp2.Display();

    cout << "temp6 = temp3 + temp4:\n";
    Cpmv temp6 = temp3 + temp4;
    cout << "temp6:\n";
    temp6.Display();

    return 0;
}
