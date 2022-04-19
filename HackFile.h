//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKFILE_H
#define HACKNETOS_HACKFILE_H

#include <string>

class HackFile
{
    std::string name;

public:


    virtual std::string cat() = 0;

    virtual HackFile* copy()=0;
    const std::string& getName() {
        return name;
    }

    void setName(const std::string &name)
    {
        HackFile::name = name;
    }

};
class HackTxtFile:HackFile
{
    std::wstring contain;
public:
   virtual std::string cat();
    HackFile * copy() override;
};
class HackBinFile:HackFile
{
    virtual std::string cat();
    std::wstring contain;
    HackBinFile* copy() override;

};

#endif //HACKNETOS_HACKFILE_H
