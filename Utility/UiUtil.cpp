//
// Created by epiphyllum on 22/04/15.
//
#include <iostream>

#include "UiUtil.h"
#include "Util.h"

using namespace Util;
using std::cout;



void UIUtil::drawFramework()
{
    // Title of MEM
    setCursorPos(0, 0);
    setColorAttr(BG_WHITE);
    setColorAttr(FG_BLACK);
    cout << " <MEMORY>"; // 9
    for (int i = 0; i < 31; i++)
    {
        cout << ' ';
    }
    cout << ' ';
    // Title of STATUS
    cout << " <STATUS>"; // 9
    for (int i = 0; i < 170; i++)
    {
        cout << ' ';
    }
    // Draw a vertical line for MEM | TERM x = 40 l = 50
    for (int i = 0; i < 50; ++i)
    {
        setCursorPos(40, i);
        cout << ' ';
    }

    // Draw a horizontal line for STATUS | TERM
    setCursorPos(41, 6);
    cout << " <TERMINAL>"; // 11
    for (int i = 0; i < 168; i++)
    {
        cout << ' ';
    }
    setColorAttr(ATTR_NORMAL);

}
