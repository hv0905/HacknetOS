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
    int currentFrame = 0;
    int count = 0;

public:
    AsciiAnimation();

    AsciiAnimation(std::filesystem::path dir, int frames);


};


#endif //HACKNETOS_ASCIIANIMATION_H
