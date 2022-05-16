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
    std::vector<HackServer *> connectedServers{};

public:

    ShellBgTask(HacknetApplication *ref, const std::string &tname) : HackBackgroundTask(ref, tname)
    {
    }

    void drawMemory(Coord begin) override;

    int getMemorySize() override;

    [[nodiscard]] const std::vector<HackServer *> &getConnectedServers() const;

    std::vector<HackServer *> &getConnectedServers();

    void setConnectedServers(const std::vector<HackServer *> &connectedServers);

    [[nodiscard]] bool isAttackingActive() const;
};


#endif //HACKNETOS_SHELLBGTASK_H
