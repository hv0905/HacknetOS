//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKNETAPPLICATION_H
#define HACKNETOS_HACKNETAPPLICATION_H

#include "HackDirectory.h"

class HacknetApplication
{
    int gameStatus = 0;

    HackDirectory root;

public:
    void Exec();
    void Draw();
};


#endif //HACKNETOS_HACKNETAPPLICATION_H
