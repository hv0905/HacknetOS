//
// Created by epiphyllum on 22/04/23.
//

#include "SshCrackBgTask.h"
#include "../HacknetApplication.h"
#include "../Utility/Util.h"

void SSHCrackBgTask::renderMemory(Coord begin)
{
    animation.getData()[std::min((currentFrame - 1) / 2, FRAME_COUNT - 1)].draw(begin);

}

int SSHCrackBgTask::getMemorySize()
{
    return 13;
}

SSHCrackBgTask::SSHCrackBgTask(HacknetApplication *ref, const std::string &threadName) : HackBackgroundTask(ref,
                                                                                                            threadName)
{}

void SSHCrackBgTask::tick()
{
    currentFrame++;
    if (ref->getCurrentConnected() == nullptr)
    {
        // failed
        stopped = true;
        ref->pushLog("SSHCrack: FATAL: Server disconnected. Stop.");
        ref->getRenderService().setRequireUpdate(true);
    }
    if (currentFrame == FRAME_COUNT * 2)
    {
        // unlock the permission
        ref->getCurrentConnected()->setSshLocked(false);
        ref->pushLog("--SecureShellCrack Completed--");
        ref->getRenderService().setRequireUpdate(true);
    }
    if (currentFrame == 2 * FRAME_COUNT + 20)
    {
        // exit
        stopped = true;
    }
}
