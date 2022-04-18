//
// Created by epiphyllum on 22/04/17.
//

#include <iostream>
#include "TutorialBgTask.h"
#include "../Utility/Util.h"

void TutorialBgTask::drawMemory(Coord begin)
{
    Util::setCursorPos(begin);
    std::cout << "这只是个用来测试的进程";
}

int TutorialBgTask::getMemorySize()
{
    return 10;
}

void TutorialBgTask::kill()
{
    HackBackgroundTask::kill();
}
