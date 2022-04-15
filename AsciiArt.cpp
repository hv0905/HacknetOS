//
// Created by epiphyllum on 22/04/14.
//

#include "AsciiArt.h"
#include <fstream>
#include <stdexcept>

void AsciiArt::draw(Coord begin)
{
    // todo: implement
}

AsciiArt::AsciiArt(const Size2D &size, const std::vector<std::string> &data) : size(size), data(data)
{}

AsciiArt::AsciiArt(const std::string &asciiFile) : size(), data()
{
    std::ifstream file(asciiFile, std::ios::in);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + asciiFile);

    std::string line;
    int maxLen = 0;
    while (std::getline(file, line))
    {
        maxLen = std::max(maxLen, (int) line.length());
        data.push_back(line);
    }

    size.width = maxLen;
    size.height = (int) data.size();

    file.close();

}
