//
// Created by epiphyllum on 22/04/09.
//

#include "HackDirectory.h"
#include <algorithm>

HackDirectory::HackDirectory(std::string name) : name(name)
{
}

std::string HackDirectory::getDirName()
{
    return (*this).name;
}

std::vector<HackDirectory *> &HackDirectory::getsubDirs()
{
    return subDirs;
}

std::vector<HackFile *> &HackDirectory::getfiles()
{
    return files;
}

HackDirectory *HackDirectory::getParentDir()
{
    return parentDir;
}

[[maybe_unused]] HackDirectory *HackDirectory::getRootDir()
{
    return rootDirs;
}

std::string HackDirectory::setDirName(std::string newName)
{
    (*this).name = newName;
    return newName;
}

void HackDirectory::AppendFile(HackFile *file)
{
    file->setParentDir(this);
    files.push_back(file);
}

HackDirectory *HackDirectory::LocateSonDir(std::string item)
{
    if (item == ".")
    {
        return this;
    }
    if (item == "..")
    {
        return getParentDir();
    }
    else
    {
        auto it = std::find_if(getsubDirs().begin(), getsubDirs().end(), [&item](HackDirectory *t)
        {
            return t->getDirName() == item;
        });
        return it == getsubDirs().end() ? nullptr : *it;
    }
}

HackDirectory *HackDirectory::LocateOrCreateSonDir(std::string item)
{
    auto d = LocateSonDir(item);
    if (d == nullptr && item != "..")
    {
        d = new HackDirectory(item);
        d->parentDir = this;
        subDirs.push_back(d);
    }

    return d;
}

HackFile *HackDirectory::LocateFile(std::string item)
{
    auto it = std::find_if(getfiles().begin(), getfiles().end(), [&item](HackFile *t)
    {
        return t->getName() == item;
    });
    return it == getfiles().end() ? nullptr : *it;
}

void HackDirectory::AppendDirectory(HackDirectory *dir)
{
    dir->parentDir = this;
    subDirs.push_back(dir);
}

HackDirectory::~HackDirectory()
{
    for (auto &i: subDirs)
    {
        delete i;
    }
    for (auto &i: files)
    {
        delete i;
    }
}

std::string HackDirectory::getAbsolutePath()
{
    if (parentDir == nullptr)
    {
        return "/";
    }
    else
    {
        return parentDir->getAbsolutePath() + name + "/";
    }
}

void HackDirectory::setParentDir(HackDirectory *parentDir)
{
    HackDirectory::parentDir = parentDir;
}

void HackDirectory::sort()
{
    std::sort(subDirs.begin(), subDirs.end(), [](HackDirectory *a, HackDirectory *b)
    {
        return a->getDirName() < b->getDirName();
    });
    std::sort(files.begin(), files.end(), [](HackFile *a, HackFile *b)
    {
        return a->getName() < b->getName();
    });
}




