//
// Created by epiphyllum on 22/04/15.
//
#include <iostream>

#include "UiUtil.h"
#include "Util.h"

using namespace Util;
using std::cout;

// 220 * 50

// MEM: 40 * 49 (1 line) 0 ~ 39 1 ~ 49

// STATUS 179 * 5 (1 line) 41 ~ 219 1 ~ 5

// TERM 179 * 43  7 ~ 49

void UIUtil::drawFramework()
{
    // Title of MEM
    setCursorPos(0, 0);
    cout << "-<MEMORY>"; // 9
    for (int i = 0; i < 31; i++)
    {
        cout << '-';
    }
    cout << ' ';
    // Title of STATUS
    cout << "-<STATUS>"; // 9
    for (int i = 0; i < 170; i++)
    {
        cout << '-';
    }
    // Draw a vertical line for MEM | TERM x = 40 l = 50
    for (int i = 0; i < 50; ++i)
    {
        setCursorPos(40, i);
        cout << '|';
    }

    // Draw a horizontal line for STATUS | TERM
    setCursorPos(41, 6);
    cout << "-<TERMINAL>"; // 11
    for (int i = 0; i < 168; i++)
    {
        cout << '-';
    }

}
