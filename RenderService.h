//
// Created by epiphyllum on 22/04/22.
//

#ifndef HACKNETOS_RENDERSERVICE_H
#define HACKNETOS_RENDERSERVICE_H

#include <string>

class HacknetApplication;

class RenderService
{


    HacknetApplication *ref;

public:
    bool requireUpdate = true;

    RenderService(HacknetApplication *ref);

    void RenderTick();

    void RenderStatusBar();

    void RenderTerminal();
};


#endif //HACKNETOS_RENDERSERVICE_H
