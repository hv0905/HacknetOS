//
// Created by epiphyllum on 22/04/19.
//

#include "HackBinFile.h"
#include <random>


HackBinFile *HackBinFile::clone()
{
    return new HackBinFile(*this);
}

std::string HackBinFile::cat()
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

const HackCommand &HackBinFile::getRelatedCommand() const
{
    return relatedCommand;
}

HackBinFile::HackBinFile(const std::string &name, const HackCommand &relatedCommand) : HackFile(name),
                                                                                       relatedCommand(relatedCommand),
                                                                                       binarySeed(_binarySeedPool++)
{}

HackBinFile::HackBinFile(const HackCommand &relatedCommand) : relatedCommand(relatedCommand),
                                                              binarySeed(_binarySeedPool++)
{}
