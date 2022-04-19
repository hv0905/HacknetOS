//
// Created by epiphyllum on 22/04/19.
//

#ifndef HACKNETOS_HACKTXTFILE_H
#define HACKNETOS_HACKTXTFILE_H

#include "HackFile.h"

class HackTxtFile : HackFile
{
    std::wstring contain;
public:
    HackFile *clone() override;

    std::string cat() override;
};


#endif //HACKNETOS_HACKTXTFILE_H
