//
// Created by epiphyllum on 22/04/09.
//

#include "HackDirectory.h"

HackDirectory::HackDirectory(std::string name):name(name)
{
}

std::string HackDirectory::getDirName()
{
    return (*this).name;
}

std::vector<HackDirectory *> &HackDirectory::getsubDirs()
{
    return subDirs;
}

std::vector<HackFile *> &HackDirectory::getfiles()
{
    return files;
}

HackDirectory *HackDirectory::getParentDir()
{
    return parentDirs;
}

HackDirectory *HackDirectory::getRootDir()
{
    return rootDirs;
}




