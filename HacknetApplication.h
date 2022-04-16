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

public:
    void Exec();
    void Draw();
    void cdDir();
};



#endif //HACKNETOS_HACKNETAPPLICATION_H
