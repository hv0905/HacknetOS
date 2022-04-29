//
// Created by epiphyllum on 22/04/27.
//

#ifndef HACKNETOS_HACKMAILVIEWER_H
#define HACKNETOS_HACKMAILVIEWER_H

#include "HackEmail.h"

class HackMailViewer
{
    HackEmail content;

public:

    HackMailViewer(const HackEmail &content);

    bool Exec();

    void Render();


};


#endif //HACKNETOS_HACKMAILVIEWER_H
