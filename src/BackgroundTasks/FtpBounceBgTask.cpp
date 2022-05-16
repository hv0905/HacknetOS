//
// Created by epiphyllum on 22/04/23.
//

#include "FtpBounceBgTask.h"
#include "../HacknetApplication.h"

void FTPBounceBgTask::drawMemory(Coord begin)
{
    animation.getData()[std::min(currentFrame++ / 2, FRAME_COUNT - 1)].draw(begin);
    if (ref->getCurrentConnected() == nullptr)
    {
        // failed
        stopped = true;
        ref->pushLog("FTPBounce: FATAL: Server disconnected. Stop.");
        ref->getRenderService().setRequireUpdate(true);
    }
    if (currentFrame == FRAME_COUNT * 2)
    {
        // unlock the permission
        ref->getCurrentConnected()->setFtpLocked(false);
        ref->pushLog("FTPBounce: Operation Complete.");
        ref->getRenderService().setRequireUpdate(true);
    }
    if (currentFrame == 2 * FRAME_COUNT + 20)
    {
        // exit
        stopped = true;
    }
}

int FTPBounceBgTask::getMemorySize()
{
    return 12;
}

FTPBounceBgTask::FTPBounceBgTask(HacknetApplication *ref, const std::string &threadName) : HackBackgroundTask(ref,
                                                                                                              threadName)
{}
