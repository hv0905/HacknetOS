//
// Created by epiphyllum on 22/04/22.
//

#include "AsciiAnimation.h"
#include <filesystem>

AsciiAnimation::AsciiAnimation()
{}

AsciiAnimation::AsciiAnimation(std::filesystem::path dir, int count) : count(count)
{
    data.reserve(count);
    for (int i = 0; i < count; ++i)
    {
        data.emplace_back((dir / (std::to_string(i) + ".ascii")).string());
    }
}
