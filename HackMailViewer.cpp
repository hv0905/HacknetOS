//
// Created by epiphyllum on 22/04/27.
//

#include <iostream>
#include <conio.h>
#include "HackMailViewer.h"
#include "Utility/Util.h"
#include "Utility/UiUtil.h"

void HackMailViewer::Render()
{
    using namespace Util;
    // Title
    setCursorPos(0, 0);
    setColorAttr(BG_WHITE);
    setColorAttr(FG_BLACK);
    std::cout << " :: JMAIL ::";
    clearLine(getCursorPos(), UIUtil::SIZE_ALL.width - getCursorPos().x);
    setColorAttr(ATTR_NORMAL);

    // Title Sender
    setCursorPos(0, 1);
    std::wcout << content.getEmailTitle();

    setCursorPos(0, 2);
    std::cout << "From: ";
    std::wcout << content.getSender();

    setCursorPos(0, 3);
    std::cout << "To: Aiden Pearce";

    setColorAttr(BG_LIGHT_BLUE);
    clearLine(Coord(0, 4), UIUtil::SIZE_ALL.width);
    setColorAttr(ATTR_NORMAL);

    // Content
    setCursorPos(0, 5);
    std::wcout << content.getEmailContent();

    // Operations
    setCursorPos(0, UIUtil::SIZE_ALL.height - 1);
    std::cout << "[ENTER / R] Reply [Q / ESC] Quit";
}

bool HackMailViewer::Exec()
{
    Render();
    while (true)
    {
        switch (_getch())
        {
            case 13:
            case 'r':
            case 'R':
                return true;
            case 'q':
            case 'Q':
            case 0x1B:
                return false;
            default:
                break;
        }
    }
}
