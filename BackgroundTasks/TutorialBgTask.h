//
// Created by epiphyllum on 22/04/17.
//

#ifndef HACKNETOS_TUTORIALBGTASK_H
#define HACKNETOS_TUTORIALBGTASK_H

#include "HackBackgroundTask.h"

class TutorialBgTask : public HackBackgroundTask
{

public:
    void drawMemory(Coord begin) override;

    int getMemorySize() override;

    void kill() override;
};


#endif //HACKNETOS_TUTORIALBGTASK_H
