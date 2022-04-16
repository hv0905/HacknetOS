//
// Created by epiphyllum on 22/04/09.
//

#include "HacknetApplication.h"
std::vector<std::string>displayedCommand;
void HacknetApplication::Exec()
{

}

void HacknetApplication::Draw()
{

}

void HacknetApplication::lsDir()
{
    if (CurrentDir->getsubDirs().empty()&&CurrentDir->getfiles().empty())
    {
        displayedCommand.emplace_back("There is no file and directory in this folder.");
        return;
    }

    displayedCommand.emplace_back("-----------------------------");
    displayedCommand.push_back("The contain of" + CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
    for (auto i: CurrentDir->getsubDirs())
    {
        displayedCommand.push_back(":" + i->getDirName());
    }
    for (auto i: CurrentDir->getfiles())
    {
        displayedCommand.push_back(":" + i->getName());
    }
    displayedCommand.emplace_back("-----------------------------");
}

void HacknetApplication::cdDir(const std::string& dirName)
{
    bool flag = false;
    for (int i=0;i<CurrentDir->getsubDirs().size();i++)
    {
        if (CurrentDir->getsubDirs()[i]->getDirName() == dirName)
        {
            flag = true;
            CurrentDir = (CurrentDir->getsubDirs()[i]);
            displayedCommand.push_back(CurrentConnected->getIp()+"@>"+dirName);
            break;
        }
    }
    if(!flag)
        displayedCommand.emplace_back("Can't find the directory.");
}

[[maybe_unused]] void HacknetApplication::rmsubDir()
{
    for (auto i:CurrentDir->getsubDirs())
    {
        displayedCommand.emplace_back("Deleting");
        displayedCommand.emplace_back(i->getDirName());
    }
    for (auto i:CurrentDir->getfiles())
    {
        displayedCommand.emplace_back("Deleting");
        displayedCommand.emplace_back(i->getName());
    }
    CurrentDir->getsubDirs().clear();
}

void HacknetApplication::rmDir(const std::string &dirName)
{
    if(CurrentDir->getsubDirs().empty())
    {
        displayedCommand.emplace_back("");
    }
    for (int i = 0; i < CurrentDir->getsubDirs().size(); i++)
    {
        if (CurrentDir->getsubDirs()[i]->getDirName() == dirName)
        {
            CurrentDir->getsubDirs().erase(CurrentDir->getsubDirs().begin() + i);
            displayedCommand.emplace_back("Deleting");
            displayedCommand.emplace_back(CurrentDir->getsubDirs()[i]->getDirName());
            break;
        }
    }
    for (int i = 0; i < CurrentDir->getfiles().size(); i++)
    {
        if (CurrentDir->getfiles()[i]->getName() == dirName)
        {
            CurrentDir->getfiles().erase(CurrentDir->getfiles().begin() + i);
            displayedCommand.emplace_back("Deleting");
            displayedCommand.emplace_back(CurrentDir->getfiles()[i]->getName());
            break;
        }
    }
}

void HacknetApplication::cdParentDir()
{
    CurrentDir=CurrentDir->getParentDir();
    displayedCommand.push_back(CurrentConnected->getIp()+"@>"+CurrentDir->getDirName());
}

void HacknetApplication::cdRootDir()
{
    CurrentDir=CurrentDir->getRootDir();
    displayedCommand.push_back(CurrentConnected->getIp()+"@>"+CurrentDir->getDirName());
}







