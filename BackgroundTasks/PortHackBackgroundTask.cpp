//
// Created by epiphyllum on 22/04/21.
//

#include "PortHackBackgroundTask.h"
#include "../Utility/Util.h"
#include "../HacknetApplication.h"
#include <utility>
#include <iostream>

void PortHackBackgroundTask::drawMemory(Coord begin)
{
    animation.getData()[std::max(currentFrame++, FRAME_COUNT - 1)].draw(begin);
    if (ref->getCurrentConnected() == nullptr)
    {
        // failed
        stopped = true;
        ref->getCommandBuffer().emplace_back("PortHack: FATAL: Server disconnected. Stop.");
    }
    if (currentFrame == FRAME_COUNT)
    {
        // unlock the permission
        ref->getCurrentConnected()->setAccessible(true);
    }
    if (currentFrame >= FRAME_COUNT)
    {
        // show a complete message
        Util::setColorAttr(Util::FG_GREEN);
        Util::setCursorPos(begin + Coord(13, 19));
        std::cout << "--------------";
        Util::setCursorPos(begin + Coord(13, 20));
        std::cout << "PASSWORD FOUND";
        Util::setCursorPos(begin + Coord(13, 21));
        std::cout << "--------------";
        Util::setColorAttr(Util::ATTR_NORMAL);
        // PASSWORD FOUND 14
    }
    if (currentFrame == 2 * FRAME_COUNT)
    {
        // exit
        stopped = true;
    }
}

int PortHackBackgroundTask::getMemorySize()
{
    return 15; // 40 * 15
}
