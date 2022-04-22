#include <iostream>
#include "HacknetApplication.h"
#include "Utility/Util.h"
#include "Utility/MusicUtil.h"
#include "AsciiArt.h"
#include "Utility/UiUtil.h"
#include "StarterCreator.h"
#include <Windows.h>
#include <codecvt>
#include <conio.h>

using std::cout;
using std::endl;

void AdjustWindowsSize()
{
    while (true) {
        Util::clearScreen();
        // 220 x 50
        cout << u8"请将控制台尺寸调整为220 x 50， 然后点击Enter开始游戏" << endl;
        auto size = Util::getScreenSize();

        cout << "当前尺寸: " << size.first << " x " << size.second << endl;

        if (size.first == 220 && size.second == 50) {
            cout << "按下Enter开始游戏..." << endl;
            if (_kbhit() && _getch() == 13) {
                break;
            }
        }

        while (_kbhit())
        {
            _getch();
        }

        Util::sleep(50);
    }
}

void DisplayStartPage()
{
    // Display LOGO
    Util::clearScreen();
    AsciiArt aa("ASCII/hacknet-logo.ascii");
    aa.draw(Coord(62, 15));
    Util::setCursorPos(5, 42);
    std::cout << "Created by: ";
    Util::moveCursorPos(0, -2);
    AsciiArt creator("ASCII/creator.ascii");
    creator.draw(Util::getCursorPos());
    Util::setCursorPos(92, 35);
    Util::setColorAttr(Util::FG_LIGHT_GREEN);
    std::cout << ">  Press Enter to start the game  <";
    Util::setColorAttr(Util::ATTR_NORMAL);

    while (_getch() != 13);
}

void PlayIntro()
{
    Util::clearScreen();
    Util::setCursorPos(30, 10);
    Util::printOneByOne(L"已过期14天...正在启用FailSafe模式...");
    Util::sleep(200);
    Util::setCursorPos(30, 11);
    Util::printOneByOne(L"------------------------------------------------------");
    Util::sleep(200);
    Util::setCursorPos(30, 12);
    Util::printOneByOne(L"你好.");
    Util::sleep(200);
    Util::setCursorPos(30, 13);
    Util::printOneByOne(L"这件事不对劲......比我想象中的还要奇怪.");
    Util::sleep(200);
    Util::setCursorPos(30, 14);
    Util::printOneByOne(L"我原以为我应该用过去时来写这段话, 不过恐怕我得承认......这件事还没有画上句号.");
    Util::sleep(200);
    Util::setCursorPos(30, 15);
    Util::printOneByOne(L"我的名字是Bit, 如果你正在阅读这封邮件, 那意味着我已经死了.");
    Util::sleep(3000);
    Util::clearScreen();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Util::EnableVTMode();
    std::ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

#pragma warning (disable: 4996)
    std::locale utf8(std::locale(), new std::codecvt_utf8_utf16<wchar_t>);
    std::wcout.imbue(utf8);
#pragma warning (default: 4996)

    AdjustWindowsSize();

    MusicUtil::playBgm(0);
    // Play the intro
    DisplayStartPage();
    PlayIntro();

    // create a starter
    auto app = StarterCreator::createStarterOS();
    HacknetApplication::current = app;
    // start the event loop
    app->Exec();

    delete app;

    UIUtil::drawFramework();
    Util::sleep(10000);
    return 0;
}
