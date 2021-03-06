//
// Created by epiphyllum on 22/04/21.
//

#include "PortHackBackgroundTask.h"
#include "../Utility/Util.h"
#include "../HacknetApplication.h"
#include <utility>
#include <iostream>

void PortHackBackgroundTask::renderMemory(Coord begin)
{
    animation.getData()[std::min(currentFrame - 1, FRAME_COUNT - 1)].draw(begin);
    if (currentFrame >= FRAME_COUNT)
    {
        // show a complete message
        Util::setColorAttr(Util::FG_GREEN);
        Util::setCursorPos(begin + Coord(13, 6));
        std::cout << "--------------";
        Util::setCursorPos(begin + Coord(13, 7));
        std::cout << "PASSWORD FOUND";
        Util::setCursorPos(begin + Coord(13, 8));
        std::cout << "--------------";
        Util::setColorAttr(Util::ATTR_NORMAL);
        // PASSWORD FOUND 14
    }
}

int PortHackBackgroundTask::getMemorySize()
{
    return 15; // 40 * 15
}

PortHackBackgroundTask::PortHackBackgroundTask(HacknetApplication *ref, const std::string &threadName)
        : HackBackgroundTask(ref, threadName)
{}

void PortHackBackgroundTask::tick()
{
    currentFrame++;
    if (ref->getCurrentConnected() == nullptr)
    {
        // failed
        stopped = true;
        ref->pushLog("PortHack: FATAL: Server disconnected. Stop.");
        ref->getRenderService().setRequireUpdate(true);
    }
    if (currentFrame == FRAME_COUNT)
    {
        // unlock the permission
        ref->getCurrentConnected()->setAccessible(true);
        ref->setShellProgress(-1);
        ref->pushLog("--PortHack complete--");
        ref->getRenderService().setRequireUpdate(true);
    }
    if (currentFrame == 2 * FRAME_COUNT)
    {
        // exit
        stopped = true;
    }
}
