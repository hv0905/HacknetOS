//
// Created by epiphyllum on 22/04/19.
//

#include "HackBinFile.h"


HackBinFile *HackBinFile::clone()
{
    return new HackBinFile(*this);
}

std::string HackBinFile::cat()
{
    return "Not Implement Yet";
}
