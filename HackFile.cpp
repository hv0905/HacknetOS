//
// Created by epiphyllum on 22/04/09.
//

#include "HackFile.h"

HackFile *HackTxtFile::copy()
{
   HackTxtFile temp;
   return (&temp);
}

HackBinFile *HackBinFile::copy()
{
    HackBinFile temp;
    return (&temp);
}
