//
// Created by epiphyllum on 22/04/20.
//

#include "CommonType.h"

Coord Coord::operator+(const Coord &c) const
{
    return Coord(x + c.x, y + c.y);
}

Coord Coord::operator-(const Coord &c) const
{
    return Coord(x - c.x, y - c.y);
}

Coord &Coord::operator+=(const Coord &c)
{
    x += c.x;
    y += c.y;
    return *this;
}

Coord &Coord::operator-=(const Coord &c)
{
    x -= c.x;
    y -= c.y;
    return *this;
}
