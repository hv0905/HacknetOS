//
// Created by epiphyllum on 22/05/07.
//

#include <random>
#include "HackBinaryFile.h"

std::string HackBinaryFile::cat()
{
    std::mt19937 rng(binarySeed);
    std::uniform_int_distribution dist(64, 512);
    int size = dist(rng);
    std::string line;
    line.reserve(size + 10);
    std::uniform_int_distribution dist2(0, 1);
    for (int i = 0; i < size; ++i)
    {
        line.push_back(dist2(rng) ? '1' : '0');
        if (i % 144 == 143)
        {
            line.push_back('\n');
        }
    }

    return line;
}

HackBinaryFile *HackBinaryFile::clone()
{
    return new HackBinaryFile(*this);
}

HackBinaryFile::HackBinaryFile(const std::string &name) : HackFile(name), binarySeed(_binarySeedPool++)
{}

HackBinaryFile::HackBinaryFile() : binarySeed(_binarySeedPool++)
{}

