#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class mean : public logic_error
{
private:
    double v1;
    double v2;

public:
    mean(const string &s = "none", double a = 0.0, double b = 0.0) : logic_error(s), v1(a), v2(b) {}
    const double &val1() const { return v1; }
    const double &val2() const { return v2; }
};

class bad_hmean : public mean
{
public:
    bad_hmean(const string &s = "none", double a = 0.0, double b = 0.0) : mean(s, a, b) {}
    void mesg() const;
};

inline void bad_hmean::mesg() const
{
    cout << "hmean(" << val1() << ", " << val2() << "):" << endl;
    cout << "hmean() arguments should be a != b" << endl;
}

class bad_gmean : public mean
{
public:
    bad_gmean(const string &s = "none", double a = 0.0, double b = 0.0) : mean(s, a, b) {}
    void mesg() const;
};

inline void bad_gmean::mesg() const
{
    cout << "gmean(" << val1() << ", " << val2() << "):" << endl;
    cout << "gmean() arguments should be >= 0" << endl;
}

#endif
