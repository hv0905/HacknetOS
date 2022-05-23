//
// Created by epiphyllum on 22/04/23.
//

#ifndef HACKNETOS_FTPBOUNCEBGTASK_H
#define HACKNETOS_FTPBOUNCEBGTASK_H

#include "HackBackgroundTask.h"
#include "../AsciiAnimation.h"

class FTPBounceBgTask : public HackBackgroundTask
{
    constexpr static const int FRAME_COUNT = 160;
    static inline AsciiAnimation animation{"ASCII/ftpbounce/", FRAME_COUNT};

    int currentFrame = 0;

public:
    FTPBounceBgTask(HacknetApplication *ref, const std::string &threadName);

    void renderMemory(Coord begin) override;

    int getMemorySize() override;

    void tick() override;
};


#endif //HACKNETOS_FTPBOUNCEBGTASK_H
