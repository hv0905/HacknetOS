//
// Created by epiphyllum on 22/04/22.
//

#include <iostream>
#include "RenderService.h"
#include "Utility/Util.h"
#include "Utility/UiUtil.h"
#include "HacknetApplication.h"
#include "AsciiArt.h"

const AsciiArt serverLogos[] = {
        AsciiArt("ASCII/laptop.ascii"),
        AsciiArt("ASCII/server.ascii"),
};

void RenderService::RenderTick()
{
    if (requireUpdate)
    {
        Util::clearScreen();
        UIUtil::drawFramework();
        RenderStatusBar();
    }
    RenderTerminal();

    requireUpdate = false;
}

void RenderService::RenderTerminal()
{
    // Area buffer
    if (requireUpdate)
    {
        int buffSize = std::min(UIUtil::SIZE_TERMINAL.height - 2, static_cast<int>(ref->commandBuffer.size()));
        int h = 0;
        for (auto it = ref->commandBuffer.end() - buffSize; it != ref->commandBuffer.end(); ++it)
        {
            Util::setCursorPos(UIUtil::START_TERMINAL + Coord(0, h++));
            std::cout << *it;
        }
    }
    else
    {
        // only update prompt
        Util::clearLine(UIUtil::START_TERMINAL + Coord(0, UIUtil::SIZE_TERMINAL.height - 1),
                        UIUtil::SIZE_TERMINAL.width);
    }

    // Area prompt
    ref->inputService.renderCMD(ref->getPrompt(), UIUtil::START_TERMINAL + Coord(0, UIUtil::SIZE_TERMINAL.height - 1));
}

void RenderService::RenderStatusBar()
{
    // write time

    if (ref->CurrentConnected == nullptr)
    {
        // disconnected
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(84, 2));
        std::cout << "已断开连接";
    }
    else
    {
        // connected
        serverLogos[1].draw(UIUtil::START_STATUSPANEL);
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 0));
        std::cout << "连接到";
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 1));
        std::cout << ref->CurrentConnected->getName();
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 2));
        std::cout << "@" << ref->CurrentConnected->getIp();
        if (ref->CurrentConnected->isAccessible())
        {
            // :: 您是本系统的管理员 ::
            Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 4));
            Util::setColorAttr(Util::BG_LIGHT_BLUE);
            Util::setColorAttr(Util::FG_BLACK);
            // 72
            for (int i = 0; i < 72; ++i)
            {
                std::cout << ' ';
            }
            std::cout << ":: 您是本系统的管理员 ::";
            for (int i = 0; i < 72; ++i)
            {
                std::cout << ' ';
            }
            Util::setColorAttr(Util::ATTR_NORMAL);
        }
    }
}

RenderService::RenderService(HacknetApplication *ref) : ref(ref)
{

}
