#include <iostream>
#include "move.h"

Move::Move(double a, double b)
{
    x = a, y = b;
}

void Move::showmove() const
{
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

Move Move::add(const Move &m) const
{
    return Move(m.x + x, m.y + y);
}

void Move::reset(double a, double b)
{
    x = a, y = b;
}
