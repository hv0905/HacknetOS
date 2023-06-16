//
// Created by epiphyllum on 22/04/25.
//

#include "HackMenuPanel.h"
#include <conio.h>
#include <iostream>
#include <algorithm>
#include "Utility/UiUtil.h"
#include "Utility/Util.h"

int HackMenuPanel::Exec()
{
    while (true)
    {
        Draw();
        auto key = _getch();
        if (key == 0xE0 || key == 0)
        { // Hit a function key or arrow key
            key = _getch();
            switch (key)
            {
                case 72:
                    // up
                    if (reverse) downItem();
                    else upItem();
                    break;
                case 80:
                    // down
                    if (reverse) upItem();
                    else downItem();
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (key)
            {
                case 13:
                    // enter
                    return currentSelection;
                case 'q':
                case 'Q':
                case 0x1B:
                    return -1;

                case 'r':
                case 'R':
                    setReverse(!reverse);
                    break;
                default:
                    break;
            }
        }
    }
}

void HackMenuPanel::Draw()
{
    using namespace Util;
    using std::cout;
    clearScreen();
    // title
    setCursorPos(0, 0);
    setColorAttr(BG_WHITE);
    setColorAttr(FG_BLACK);
    cout << title;
    clearLine(getCursorPos(), UIUtil::SIZE_ALL.width - getCursorPos().x);
    setColorAttr(ATTR_NORMAL);

    // operation Notif
    setCursorPos(0, UIUtil::SIZE_ALL.height - 1);
    cout << "[R] Reverse order     [Q / ESC] Quit    [ENTER] Go to selection";

    // menu
    for (int i = currentSkip, j = 1;
         i < std::min(static_cast<int>(items.size()), currentSkip + MAX_VISIBLE_ITEMS); i++, j++)
    {
        auto ii = reverse ? items.size() - i - 1 : i;
        setCursorPos(0, j);
        if (currentSelection == ii)
        {
            setColorAttr(BG_WHITE);
            setColorAttr(FG_BLACK);
            cout << items[ii];
            clearLine(getCursorPos(), UIUtil::SIZE_ALL.width - getCursorPos().x);
            setColorAttr(ATTR_NORMAL);
        }
        else
        {
            cout << items[ii];
        }
    }
}

void HackMenuPanel::upItem()
{
    if (currentSelection > 0)
    {
        currentSelection--;
        if (currentSelection - currentSkip < 0)
        {
            currentSkip--;
        }
    }
}

void HackMenuPanel::downItem()
{
    if (currentSelection < (int) items.size() - 1)
    {
        currentSelection++;
        if (currentSelection - currentSkip > MAX_VISIBLE_ITEMS - 1)
        {
            currentSkip++;
        }
    }

}

HackMenuPanel::HackMenuPanel(const std::string &title, const std::vector<std::string> &items) : title(title),
                                                                                                items(items)
{}

void HackMenuPanel::setReverse(bool reverse)
{
    HackMenuPanel::reverse = reverse;
    currentSelection = reverse ? items.size() - 1 : 0;
}
