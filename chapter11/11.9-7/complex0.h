#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex
{
private:
    double real;
    double imag;

public:
    complex(double r = 0, double i = 0);
    ~complex();
    complex operator+(const complex &t) const;
    complex operator-(const complex &t) const;
    complex operator*(const complex &t) const;
    complex operator*(double x) const;
    complex operator~() const;
    friend complex operator*(double x, const complex &t) { return t * x; }
    friend std::istream &operator>>(std::istream &is, complex &t);
    friend std::ostream &operator<<(std::ostream &os, const complex &t);
};

#endif
