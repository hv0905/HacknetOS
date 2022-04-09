#include <iostream>
#include "HacknetApplication.h"
#include "Util.h"
#include <Windows.h>

using std::cout;
using std::endl;

void AdjustWindowsSize() {
    cout << endl << endl << endl << endl << "Test";
    while (true) {
        Util::clearScreen();
        // 220 x 50
        cout << "请将控制台尺寸调整为220 x 50， 然后点击Enter开始游戏" << endl;
        auto size = Util::getScreenSize();

        cout << "当前尺寸: " << size.first << " x " << size.second << endl;

        if (size.first == 220 && size.second == 50) {
            break;
        }

        Util::sleep(80);
    }
}

HacknetApplication* CreateStarterOS() {
    auto app =  new HacknetApplication();
    return app;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    AdjustWindowsSize();

    // create a starter
    HacknetApplication app;


    // start the event loop
    app.Exec();


    return 0;
}
