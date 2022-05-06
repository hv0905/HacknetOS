//
// Created by epiphyllum on 22/05/07.
//

#ifndef HACKNETOS_HACKBINARYFILE_H
#define HACKNETOS_HACKBINARYFILE_H

#include "HackFile.h"


class HackBinaryFile : public HackFile
{
    static inline int _binarySeedPool = 0;
    int binarySeed;

public:
    explicit HackBinaryFile(const std::string &name);

    HackBinaryFile();

    std::string cat() override;

    HackBinaryFile *clone() override;

};


#endif //HACKNETOS_HACKBINARYFILE_H
