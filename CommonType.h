//
// Created by epiphyllum on 22/04/14.
//

#pragma once
#ifndef HACKNETOS_COMMONTYPE_H
#define HACKNETOS_COMMONTYPE_H

struct Coord {
    int x;
    int y;

    explicit Coord(int x = 0, int y = 0) : x(x), y(y)
    {}

};

struct Size2D {
    int width;
    int height;

    explicit Size2D(int width = 0, int height = 0) : width(width), height(height)
    {}
};


#endif //HACKNETOS_COMMONTYPE_H
