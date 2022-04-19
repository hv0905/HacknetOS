//
// Created by epiphyllum on 22/04/14.
//

#pragma once
#ifndef HACKNETOS_COMMONTYPE_H
#define HACKNETOS_COMMONTYPE_H

#include <utility>

struct Coord
{
    int x;
    int y;

    Coord operator+(const Coord &c) const;

    Coord operator-(const Coord &c) const;

    Coord &operator+=(const Coord &c);

    Coord &operator-=(const Coord &c);


    explicit constexpr Coord(int x = 0, int y = 0) : x(x), y(y)
    {}

    constexpr Coord(const std::pair<int, int> &p) : x(p.first), y(p.second) // NOLINT(google-explicit-constructor)
    {}
};

struct Size2D {
    int width;
    int height;

    explicit constexpr Size2D(int width = 0, int height = 0) : width(width), height(height)
    {}
};


#endif //HACKNETOS_COMMONTYPE_H
