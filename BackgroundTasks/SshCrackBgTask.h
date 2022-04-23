//
// Created by epiphyllum on 22/04/23.
//

#ifndef HACKNETOS_SSHCRACKBGTASK_H
#define HACKNETOS_SSHCRACKBGTASK_H

#include "HackBackgroundTask.h"

class SSHCrackBgTask : public HackBackgroundTask
{
public:
    void drawMemory(Coord begin) override;

    int getMemorySize() override;
};


#endif //HACKNETOS_SSHCRACKBGTASK_H
