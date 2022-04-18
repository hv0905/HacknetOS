//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKNETAPPLICATION_H
#define HACKNETOS_HACKNETAPPLICATION_H

#include "HackEmail.h"
#include "HackDirectory.h"
#include "HackServer.h"
#include "InputService.h"
#include "BackgroundTasks/HackBackgroundTask.h"

class HacknetApplication
{
    bool ending = false;
    int gameStatus = 0;
    bool doRender = true;
    HackDirectory *CurrentDir;
    HackServer *CurrentConnected;
    int missionId{};
    std::vector<std::string> commandBuffer;
    InputService inputService;
    std::vector<HackBackgroundTask *> backgroundTasks;

public:
    void Exec();

    void Draw();

    void lsDir();

    void rmsubDir();

    void cdDir(const std::string &dirName);

    void rmDir(const std::string &dirName);

    void cdParentDir();

    void cdRootDir();

    void namp();

    void command_ps();

    void command_kill(const std::string &pid);

    bool isEnding() const
    {
        return ending;
    }

    void setEnding(bool ending)
    {
        HacknetApplication::ending = ending;
    }
};

#endif //HACKNETOS_HACKNETAPPLICATION_H
