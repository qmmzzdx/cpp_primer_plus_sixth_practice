#include <iostream>
#include <string>
#include "emp.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

abstr_emp::abstr_emp() : fname("no"), lname("one"), job("none")
{
}

abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j) : fname(fn), lname(ln), job(j)
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
    os << "First name: " << e.fname << endl;
    os << "Last name: " << e.lname << endl;
    os << "Job: " << e.job;
    return os;
}

abstr_emp::~abstr_emp()
{
}

employee::employee() : abstr_emp()
{
}

employee::employee(const string &fn, const string &ln, const string &j) : abstr_emp(fn, ln, j)
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

manager::manager() : abstr_emp(), inchargeof(0)
{
}

manager::manager(const string &fn, const string &ln, const string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
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

fink::fink() : abstr_emp(), reportsto("none")
{
}

fink::fink(const string &fn, const string &ln, const string &j, const string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp &e, const string &rpo) : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink &e) : abstr_emp(e), reportsto(e.reportsto)
{
}

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

highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const string &fn, const string &ln, const string &j, const string &rpo,
                   int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp &e, const string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager &m, const string &rpo) : abstr_emp(m), manager(m), fink(m, rpo)
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
