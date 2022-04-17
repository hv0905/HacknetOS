//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKNETAPPLICATION_H
#define HACKNETOS_HACKNETAPPLICATION_H
#include "HackEmail.h"
#include "HackDirectory.h"
#include"HackServer.h"
class HacknetApplication
{
    int gameStatus = 0;
    bool doRender = true;
    HackDirectory* CurrentDir;
    HackServer* CurrentConnected;
    int missionId{};
    std::vector<std::string> displayedCommand;

public:
    void Exec();
    void Draw();
    void lsDir();
    void rmsubDir();
    void cdDir(const std::string& dirName);
    void rmDir(const std::string& dirName);
    void cdParentDir();
    void cdRootDir();
    void namp();
};



#endif //HACKNETOS_HACKNETAPPLICATION_H
