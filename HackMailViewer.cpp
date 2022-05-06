//
// Created by epiphyllum on 22/04/27.
//

#include <iostream>
#include <conio.h>
#include "HackMailViewer.h"
#include "HacknetApplication.h"
#include "AsciiArt.h"
#include "Utility/Util.h"
#include "Utility/UiUtil.h"

void HackMailViewer::Render()
{
    using namespace Util;
    clearScreen();
    // Title
    setCursorPos(0, 0);
    setColorAttr(BG_WHITE);
    setColorAttr(FG_BLACK);
    std::cout << " :: JMAIL ::";
    clearLine(getCursorPos(), UIUtil::SIZE_ALL.width - getCursorPos().x);
    setColorAttr(ATTR_NORMAL);

    // Title Sender
    setCursorPos(0, 1);
    std::wcout << content->getEmailTitle();

    setCursorPos(0, 2);
    std::cout << "From: ";
    std::wcout << content->getSender();

    setCursorPos(0, 3);
    std::cout << "To: Aiden Pearce";

    setColorAttr(BG_LIGHT_BLUE);
    clearLine(Coord(0, 4), UIUtil::SIZE_ALL.width);
    setColorAttr(ATTR_NORMAL);

    // Content
    setCursorPos(0, 5);
    std::wcout << content->getEmailContent();

    // Operations
    setCursorPos(0, UIUtil::SIZE_ALL.height - 1);
    std::cout << "[ENTER / R] Reply [Q / ESC] Quit";
}

bool HackMailViewer::Exec()
{
    content->setRead(true);
    Render();
    while (true)
    {
        switch (_getch())
        {
            case 13:
            case 'r':
            case 'R':
                if (DoReply())
                {
                    return true;
                }
                else
                {
                    Render();
                }
                break;
            case 'q':
            case 'Q':
            case 0x1B:
                return false;
            default:
                break;
        }
    }
}

HackMailViewer::HackMailViewer(HackEmail *content, HacknetApplication *ref) : content(content), ref(ref)
{}

bool HackMailViewer::DoReply()
{
    using namespace Util;

    if (content->getMode() == MODE_NO_MISSION)
    {
        // return directly
        return false;
    }

    clearScreen();
    // Title
    setCursorPos(0, 0);
    setColorAttr(BG_WHITE);
    setColorAttr(FG_BLACK);
    std::cout << " :: REPLY MAIL ::";
    clearLine(getCursorPos(), UIUtil::SIZE_ALL.width - getCursorPos().x);
    setColorAttr(ATTR_NORMAL);
    setCursorPos(10, 2);
    std::string replyText;
    if (content->getMode() == MODE_REPLY_MISSION)
    {
        std::cout << "Additional Information: ";
        setCursorPos(10, 3);
        std::getline(std::cin, replyText);
        clearLine(Coord(10, 3), UIUtil::SIZE_ALL.width - 10);
        clearLine(Coord(10, 2), UIUtil::SIZE_ALL.width - 10);
        setCursorPos(10, 2);
    }

    // check
    auto result = (ref->getCheckService().*(content->getCheckerHandler()))(replyText);
    if (result)
    {
        return true;
    }
    else
    {
        // show a failed box
        AsciiArt warningLogo("ASCII/warning.ascii");
        setColorAttr(FG_RED);
        warningLogo.draw(Coord(64, 3));
        setCursorPos(105, 25);
        setColorAttr(FG_WHITE);
        setColorAttr(BG_RED);
        std::cout << "任务未完成";
        setColorAttr(ATTR_NORMAL);
        while (_kbhit()) _getch();
        _getch();
        return false;
    }


}
