#include <iostream>
#include "emp.h"
using std::cin;
using std::cout;
using std::endl;

abstr_emp::abstr_emp() : fname("no"), lname("one"), job("none")
{
}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln,
                     const std::string &j) : fname(fn), lname(ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "Please enter your firstname: ";
    getline(cin, fname);
    cout << "Please enter your lastname: ";
    getline(cin, lname);
    cout << "Please enter your job: ";
    getline(cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << "\nFirst name: " << e.fname << endl;
    os << "Last name: " << e.lname << endl;
    os << "Job: " << e.job;
    return os;
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::writeall(std::ofstream &os)
{
    os << fname << endl;
    os << lname << endl;
    os << job << endl;
}

void abstr_emp::getall(std::ifstream &is)
{
    std::getline(is, fname);
    std::getline(is, lname);
    std::getline(is, job);
}

employee::employee() : abstr_emp()
{
}

employee::employee(const std::string &fn, const std::string &ln, const std::string &j) : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::writeall(std::ofstream &os)
{
    os << Employee << endl;
    abstr_emp::writeall(os);
}

void employee::getall(std::ifstream &is)
{
    abstr_emp::getall(is);
}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string &fn, const std::string &ln, const std::string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager &m) : abstr_emp(m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Please enter a number for inchargerof: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
        continue;
}

void manager::writeall(std::ofstream &os)
{
    os << Manager << endl;
    abstr_emp::writeall(os);
    os << inchargeof << endl;
}

void manager::getall(std::ifstream &is)
{
    abstr_emp::getall(is);
    is >> inchargeof;
}

fink::fink() : abstr_emp(), reportsto("none")
{
}

fink::fink(const std::string &fn, const std::string &ln,
           const std::string &j, const std::string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink &e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Please enter a string for reportsto: ";
    getline(cin, reportsto);
}

void fink::writeall(std::ofstream &os)
{
    os << Fink << endl;
    abstr_emp::writeall(os);
    os << reportsto << endl;
}

void fink::getall(std::ifstream &is)
{
    abstr_emp::getall(is);
    getline(is, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo,
                   int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager &m, const std::string &rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "In charge of: " << manager::InChargeOf() << endl;
    cout << "Reports to: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Please enter a number for inchargerof: ";
    cin >> InChargeOf();
    while (cin.get() != '\n')
        continue;
    cout << "Please enter a string for reportsto: ";
    getline(cin, ReportsTo());
}

void highfink::writeall(std::ofstream &os)
{
    os << Highfink << endl;
    abstr_emp::writeall(os);
    os << InChargeOf() << endl;
    os << ReportsTo() << endl;
}

void highfink::getall(std::ifstream &is)
{
    abstr_emp::getall(is);
    is >> InChargeOf();
    is >> ReportsTo();
}
