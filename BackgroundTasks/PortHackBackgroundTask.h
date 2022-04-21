//
// Created by epiphyllum on 22/04/21.
//

#ifndef HACKNETOS_PORTHACKBACKGROUNDTASK_H
#define HACKNETOS_PORTHACKBACKGROUNDTASK_H

#include "HackBackgroundTask.h"

class PortHackBackgroundTask : public HackBackgroundTask
{

public:
    void drawMemory(Coord begin) override;

    int getMemorySize() override;
};


#endif //HACKNETOS_PORTHACKBACKGROUNDTASK_H
