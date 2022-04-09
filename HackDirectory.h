//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKDIRECTORY_H
#define HACKNETOS_HACKDIRECTORY_H

#include <vector>
#include <string>
#include "HackFile.h"

class HackDirectory
{
    std::string name;

    std::vector<HackDirectory> subDirs;
    std::vector<HackFile> files;
};


#endif //HACKNETOS_HACKDIRECTORY_H
