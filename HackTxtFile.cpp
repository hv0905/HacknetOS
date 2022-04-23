//
// Created by epiphyllum on 22/04/19.
//

#include "HackTxtFile.h"
#include "Utility/StringUtil.h"

HackFile *HackTxtFile::clone()
{
    return new HackTxtFile(*this);
}

std::string HackTxtFile::cat()
{
    return StringUtil::ws2s(contain);
}

HackTxtFile::HackTxtFile(const std::string &name, const std::wstring &contain) : contain(contain), HackFile(name)
{
}
