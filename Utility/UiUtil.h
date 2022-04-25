//
// Created by epiphyllum on 22/04/15.
//

#ifndef HACKNETOS_UIUTIL_H
#define HACKNETOS_UIUTIL_H

#include "../CommonType.h"


namespace UIUtil
{
    // 220 * 50
    // MEM: 40 * 49 (1 line) 0 ~ 39 1 ~ 49
    // STATUS 179 * 5 (1 line) 41 ~ 219 1 ~ 5
    // TERM 179 * 43  7 ~ 49
    const Coord START_STATUSPANEL(41, 1);
    const Size2D SIZE_STATUSPANEL(179, 5);

    const Coord START_MEMORYPANEL(0, 1);
    const Size2D SIZE_MEMORYPANEL(40, 49);

    const Coord START_TERMINAL(41, 7);
    const Size2D SIZE_TERMINAL(179, 43);

    const Size2D SIZE_ALL(220, 50);

    void drawFramework();
}


#endif //HACKNETOS_UIUTIL_H
