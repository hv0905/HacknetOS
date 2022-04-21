//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKFILE_H
#define HACKNETOS_HACKFILE_H

#include <string>

class HackDirectory;

class HackFile
{
protected:
    std::string name;

    HackDirectory *parentDir;
public:

    HackFile(const std::string &name);

    HackFile();

    HackDirectory *getParentDir();

    virtual std::string cat() = 0;

    virtual HackFile *clone() = 0;

    const std::string &getName()
    {
        return name;
    }

    void setName(const std::string &name)
    {
        HackFile::name = name;
    }

    void setParentDir(HackDirectory *parentDir);

    virtual ~HackFile();

};

#endif //HACKNETOS_HACKFILE_H
