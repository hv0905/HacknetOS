#include <iostream>
#include "HacknetApplication.h"
#include "Util.h"
#include "MusicUtil.h"
#include "AsciiArt.h"
#include <Windows.h>
#include <codecvt>
#include <conio.h>

using std::cout;
using std::endl;

void AdjustWindowsSize() {
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
    AsciiArt aa = AsciiArt("ASCII/hacknet-logo.ascii");
    aa.draw(Coord(62, 15));
    Util::setCursorPos(92, 35);
    std::cout << ">  Press Enter to start the game  <";

    while (_getch() != 13);
}

HacknetApplication *CreateStarterOS()
{
    auto app = new HacknetApplication();

    // Add Servers, Directories, and Files here...

    return app;
}

void PlayIntro()
{
    Util::clearScreen();
    Util::setCursorPos(30, 10);
    Util::printOneByOne(L"已过期14天...正在启用FailSafe模式...");
    Util::setCursorPos(30, 11);
    Util::printOneByOne(L"------------------------------------------------------");
    Util::setCursorPos(30, 12);
    Util::printOneByOne(L"你好.");
    Util::setCursorPos(30, 13);
    Util::printOneByOne(L"这件事不对劲......比我想象中的还要奇怪.");
    Util::setCursorPos(30, 14);
    Util::printOneByOne(L"我原以为我应该用过去时来写这段话, 不过恐怕我得承认......这件事还没有画上句号.");
    Util::setCursorPos(30, 15);
    Util::printOneByOne(L"我的名字是Bit, 如果你正在阅读这封邮件, 那意味着我已经死了.");
    Util::setCursorPos(30, 16);

    Util::sleep(3000);
    Util::clearScreen();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    SetConsoleOutputCP(CP_UTF8);

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
    auto app = CreateStarterOS();

    // start the event loop
    app->Exec();

    delete app;

    Util::sleep(1000);
    return 0;
}
