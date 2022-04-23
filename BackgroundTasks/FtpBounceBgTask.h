//
// Created by epiphyllum on 22/04/23.
//

#ifndef HACKNETOS_FTPBOUNCEBGTASK_H
#define HACKNETOS_FTPBOUNCEBGTASK_H

#include "HackBackgroundTask.h"

class FTPBounceBgTask : public HackBackgroundTask
{
public:
    void drawMemory(Coord begin) override;

    int getMemorySize() override;
};


#endif //HACKNETOS_FTPBOUNCEBGTASK_H
