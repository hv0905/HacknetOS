//
// Created by epiphyllum on 22/04/09.
//

#ifndef HACKNETOS_UTIL_H
#define HACKNETOS_UTIL_H

#include <utility>

namespace Util {
    void clearScreen();
    void setCursorPos(int x, int y);
    std::pair<int,int> getScreenSize();
    void sleep(int ms);
}

#endif //HACKNETOS_UTIL_H
