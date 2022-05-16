//
// Created by epiphyllum on 22/05/07.
//

#include <iostream>
#include "ShellBgTask.h"
#include "../Utility/Util.h"
#include "../Utility/UiUtil.h"
#include "../HacknetApplication.h"

void ShellBgTask::drawMemory(Coord begin)
{
    if (isAttackingActive())
    {
        ref->setShellProgress(ref->getShellProgress() + connectedServers.size());
    }

    using namespace Util;
    setCursorPos(begin);
    setColorAttr(BG_WHITE);
    setColorAttr(FG_BLACK);

    std::cout << "Connected Shells: ";

    clearLine(getCursorPos(), UIUtil::SIZE_MEMORYPANEL.width - getCursorPos().x, true);

    setColorAttr(ATTR_NORMAL);

    for (int i = 0; i < connectedServers.size(); ++i)
    {
        setCursorPos(begin + Coord(0, 1 + i * 2));
        std::cout << connectedServers[i]->getName();
        clearLine(getCursorPos(), UIUtil::SIZE_MEMORYPANEL.width - getCursorPos().x);
        setCursorPos(begin + Coord(0, 2 + i * 2));
        if (isAttackingActive())
        {
            setColorAttr(BG_LIGHT_GREEN);
        }
        else
        {
            setColorAttr(BG_LIGHT_MAGENTA);
        }
        setColorAttr(FG_WHITE);
        std::cout << "@" << connectedServers[i]->getIp();
        clearLine(getCursorPos(), UIUtil::SIZE_MEMORYPANEL.width - getCursorPos().x);
        setColorAttr(ATTR_NORMAL);
    }
}

int ShellBgTask::getMemorySize()
{
    return connectedServers.size() * 2 + 2;
}

const std::vector<HackServer *> &ShellBgTask::getConnectedServers() const
{
    return connectedServers;
}

void ShellBgTask::setConnectedServers(const std::vector<HackServer *> &connectedServers)
{
    ShellBgTask::connectedServers = connectedServers;
}

std::vector<HackServer *> &ShellBgTask::getConnectedServers()
{
    return connectedServers;
}

bool ShellBgTask::isAttackingActive() const
{
    return ref->getShellProgress() != -1;
}
