//
// Created by epiphyllum on 22/04/16.
//

#ifndef HACKNETOS_HACKBACKGROUNDTASK_H
#define HACKNETOS_HACKBACKGROUNDTASK_H

#include <string>
#include "../HacknetApplication.h"
#include "../CommonType.h"

class HackBackgroundTask
{
protected:
    HacknetApplication *ref;
    std::string thread_name;
    int pid;
    bool stopped;

public:

    virtual void drawMemory(Coord begin) = 0;

    virtual int getMemorySize() = 0;

    virtual void kill()
    {
        stopped = true;
    }

    [[nodiscard]] const std::string &getThreadName() const
    {
        return thread_name;
    }

    [[nodiscard]] int getPid() const
    {
        return pid;
    }

    [[nodiscard]] bool isStopped() const
    {
        return stopped;
    }
};


#endif //HACKNETOS_HACKBACKGROUNDTASK_H
