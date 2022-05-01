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
public:
    explicit HackDirectory(std::string name = "[root]");

    std::string getDirName();

    std::vector<HackDirectory *> &getsubDirs();

    std::vector<HackFile *> &getfiles();

    HackDirectory *getParentDir();

    std::string setDirName(std::string newName);

    void setParentDir(HackDirectory *parentDir);

    void AppendFile(HackFile *file);

    void AppendDirectory(HackDirectory *dir);

    void sort();

    // This method can handle '..' and '.' cases!
    // Only 1 elem, cannot include '/', for path, use locateDir in HApp instead.
    HackDirectory *LocateSonDir(std::string item);

    HackDirectory *LocateOrCreateSonDir(const std::string &item);

    HackFile *LocateFile(std::string item);

    std::string getAbsolutePath();

    HackDirectory *clone();

    ~HackDirectory();

private:

    std::string name{};
    HackDirectory *rootDirs{};
    HackDirectory *parentDir{};
    std::vector<HackDirectory *> subDirs{};
    std::vector<HackFile *> files{};

};


#endif //HACKNETOS_HACKDIRECTORY_H
