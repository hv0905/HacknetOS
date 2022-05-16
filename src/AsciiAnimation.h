//
// Created by epiphyllum on 22/04/22.
//

#ifndef HACKNETOS_ASCIIANIMATION_H
#define HACKNETOS_ASCIIANIMATION_H

#include "AsciiArt.h"
#include <vector>
#include <filesystem>

class AsciiAnimation
{
    std::vector<AsciiArt> data{};

public:
    AsciiAnimation();

    AsciiAnimation(const std::filesystem::path &dir, int frames);

    [[nodiscard]] const std::vector<AsciiArt> &getData() const;

    void setData(const std::vector<AsciiArt> &data);
};


#endif //HACKNETOS_ASCIIANIMATION_H
