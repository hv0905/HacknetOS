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

    virtual HackFile *clone() = 0;

    const std::string &getName()
    {
        return name;
    }

    void setName(const std::string &name)
    {
        HackFile::name = name;
    }

};

#endif //HACKNETOS_HACKFILE_H
