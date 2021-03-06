//
// Created by epiphyllum on 22/04/14.
//

#pragma once
#ifndef HACKNETOS_ASCIIART_H
#define HACKNETOS_ASCIIART_H

#include <string>
#include <vector>
#include "CommonType.h"

class AsciiArt
{
    Size2D size;
    std::vector<std::string> data;

public:
    AsciiArt(const Size2D &size, const std::vector<std::string> &data);

    explicit AsciiArt(const std::string &asciiFile);

    void draw(Coord begin) const;

    [[nodiscard]] const Size2D &getSize() const
    {
        return size;
    }

    [[nodiscard]] const std::vector<std::string> &getData() const
    {
        return data;
    }

};


#endif //HACKNETOS_ASCIIART_H
