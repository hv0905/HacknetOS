//
// Created by epiphyllum on 22/04/19.
//

#include "HackTxtFile.h"

HackFile *HackTxtFile::clone()
{
    return new HackTxtFile(*this);
}

std::string HackTxtFile::cat()
{
    return "Not Implement Yet";
}

HackTxtFile::HackTxtFile(const std::string &name, const std::wstring &contain) : contain(contain), HackFile(name)
{
}
