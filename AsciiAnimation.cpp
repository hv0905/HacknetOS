//
// Created by epiphyllum on 22/04/22.
//

#include "AsciiAnimation.h"
#include <filesystem>

AsciiAnimation::AsciiAnimation()
{}

AsciiAnimation::AsciiAnimation(std::filesystem::path dir, int count)
{
    data.reserve(count);
    for (int i = 0; i < count; ++i)
    {
        data.emplace_back((dir / (std::to_string(i) + ".ascii")).string());
    }
}

const std::vector<AsciiArt> &AsciiAnimation::getData() const
{
    return data;
}

void AsciiAnimation::setData(const std::vector<AsciiArt> &data)
{
    AsciiAnimation::data = data;
}
