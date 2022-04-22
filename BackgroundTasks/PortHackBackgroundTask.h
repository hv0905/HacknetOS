//
// Created by epiphyllum on 22/04/21.
//

#ifndef HACKNETOS_PORTHACKBACKGROUNDTASK_H
#define HACKNETOS_PORTHACKBACKGROUNDTASK_H

#include "HackBackgroundTask.h"
#include "../AsciiAnimation.h"

class PortHackBackgroundTask : public HackBackgroundTask
{
    constexpr static const int FRAME_COUNT = 120;
    static inline AsciiAnimation animation{"ASCII/porthack/", FRAME_COUNT};

    int currentFrame = 0;

public:

    PortHackBackgroundTask(HacknetApplication *ref, const std::string &threadName);

    void drawMemory(Coord begin) override;

    int getMemorySize() override;
};


#endif //HACKNETOS_PORTHACKBACKGROUNDTASK_H
