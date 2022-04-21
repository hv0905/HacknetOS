//
// Created by epiphyllum on 22/04/09.
//

#include "HackFile.h"

HackDirectory *HackFile::getParentDir()
{
    return parentDir;
}

void HackFile::setParentDir(HackDirectory *parentDir)
{
    HackFile::parentDir = parentDir;
}

HackFile::~HackFile()
{

}

HackFile::HackFile(const std::string &name) : name(name)
{}

HackFile::HackFile()
{}
