//
// Created by epiphyllum on 22/04/19.
//

#ifndef HACKNETOS_HACKBINFILE_H
#define HACKNETOS_HACKBINFILE_H

#include "HackFile.h"

class HackBinFile : HackFile
{

public:
    HackBinFile *clone() override;

    std::string cat() override;

};


#endif //HACKNETOS_HACKBINFILE_H
