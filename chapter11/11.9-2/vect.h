#ifndef VECT_H_
#define VECT_H_
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode{ RECT, POL };

    private:
        double x;
        double y;
        Mode mode;
        double set_mag() const;             //修改了原来设置矢量长度的函数;
        double set_ang() const;             //修改了原来设置矢量角度的函数;
        void set_x(double mag, double ang); //修改了原来设置矢量x坐标的函数;
        void set_y(double mag, double ang); //修改了原来设置矢量y坐标的函数;

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return set_mag(); }
        double angval() const { return set_ang(); }
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };
}

#endif
