//
// Created by epiphyllum on 22/04/21.
//

#ifndef HACKNETOS_PORTHACKBACKGROUNDTASK_H
#define HACKNETOS_PORTHACKBACKGROUNDTASK_H

#include "HackBackgroundTask.h"
#include "../AsciiAnimation.h"

class PortHackBackgroundTask : public HackBackgroundTask
{
    static inline AsciiAnimation animation{"ASCII/porthack/", 120};

public:

    void drawMemory(Coord begin) override;

    int getMemorySize() override;
};


#endif //HACKNETOS_PORTHACKBACKGROUNDTASK_H
