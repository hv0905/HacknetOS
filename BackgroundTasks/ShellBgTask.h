//
// Created by epiphyllum on 22/05/07.
//

#ifndef HACKNETOS_SHELLBGTASK_H
#define HACKNETOS_SHELLBGTASK_H

#include "HackBackgroundTask.h"
#include "../HackServer.h"
#include <vector>


class ShellBgTask : public HackBackgroundTask
{
    std::vector<HackServer *> connectedServers;

public:
    void drawMemory(Coord begin) override;

    int getMemorySize() override;
};


#endif //HACKNETOS_SHELLBGTASK_H
