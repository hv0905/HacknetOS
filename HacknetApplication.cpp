//
// Created by epiphyllum on 22/04/09.
//

#include "HacknetApplication.h"


void HacknetApplication::Exec()
{

}

void HacknetApplication::Draw()
{

}

void HacknetApplication::cdDir()
{
    displayedCommand.emplace_back("-----------------------------");
    displayedCommand.push_back("The contain of" + CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
    for (auto &i: CurrentDir->getsubDirs())
    {
        displayedCommand.push_back(":" + i->getDirName());
    }
    displayedCommand.emplace_back("-----------------------------");
}
