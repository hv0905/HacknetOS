//
// Created by epiphyllum on 22/04/27.
//

#ifndef HACKNETOS_HACKMAILVIEWER_H
#define HACKNETOS_HACKMAILVIEWER_H

#include "HackEmail.h"

class HackMailViewer
{
    HackEmail *content;
    HacknetApplication *ref;

public:

    explicit HackMailViewer(HackEmail *content, HacknetApplication *ref);

    bool Exec();

    void Render();

    bool DoReply();


};


#endif //HACKNETOS_HACKMAILVIEWER_H
