//
// Created by epiphyllum on 22/04/23.
//

#ifndef HACKNETOS_SSHCRACKBGTASK_H
#define HACKNETOS_SSHCRACKBGTASK_H

#include "HackBackgroundTask.h"
#include "../AsciiAnimation.h"

class SSHCrackBgTask : public HackBackgroundTask
{
    constexpr static const int FRAME_COUNT = 60;
    static inline AsciiAnimation animation{"ASCII/sshcrack/", FRAME_COUNT};

    int currentFrame = 0;

public:
    SSHCrackBgTask(HacknetApplication *ref, const std::string &threadName);

    void renderMemory(Coord begin) override;

    int getMemorySize() override;

    void tick() override;
};


#endif //HACKNETOS_SSHCRACKBGTASK_H
