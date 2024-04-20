#include <iostream>
#include "complex0.h"

complex::complex(double r, double i)
{
    real = r, imag = i;
}

complex::~complex()
{
}

complex complex::operator+(const complex &t) const
{
    return complex(real + t.real, imag + t.imag);
}

complex complex::operator-(const complex &t) const
{
    return complex(real - t.real, imag - t.imag);
}

complex complex::operator*(const complex &t) const
{
    return complex(real * t.real - imag * t.imag, real * t.imag + imag * t.real);
}

complex complex::operator*(double x) const
{
    return complex(x * real, x * imag);
}

complex complex::operator~() const
{
    return complex(real, -imag);
}

std::istream &operator>>(std::istream &is, complex &t)
{
    std::cout << "real: ";
    if (is >> t.real)
    {
        std::cout << "imaginary: ";
        is >> t.imag;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const complex &t)
{
    os << "(" << t.real << "," << t.imag << "i)";
    return os;
}
