#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class bad_hmean : public logic_error
{
public:
    explicit bad_hmean(const string &s = "Error in bad_hmean object\nhmean() arguments should be a != -b\n") : logic_error(s) {}
};

class bad_gmean : public logic_error
{
public:
    explicit bad_gmean(const string &s = "Error in bad_hmean object\ngmean() arguments should be >= 0\n") : logic_error(s) {}
};

#endif
