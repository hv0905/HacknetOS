//
// Created by epiphyllum on 22/04/14.
//

#include <conio.h>
#include <iostream>

#include "InputService.h"
#include "Utility/StringUtil.h"
#include "Utility/Util.h"

std::optional<std::string> InputService::tickInput()
{
    while (_kbhit())
    {
        int key = _getch();
        if (key == 0xE0 || key == 0)
        { // Hit a function key or arrow key
            key = _getch();
            if (!acceptCommand) continue;
            switch (key)
            {
                case 72:
                    // TODO CHECK LOG
                    if (historyMov < history.size())
                    {
                        ++historyMov;
                        position = 0;
                        commandBuffer = history[history.size() - historyMov];
                    }
//                    _input = Input::UP;
                    break;
                case 80:
                    // TODO CHECK LOG
                    if (historyMov > 1)
                    {
                        --historyMov;
                        position = 0;
                        commandBuffer = history[history.size() - historyMov];
                    }
//                    _input = Input::DOWN;
                    break;
                case 75:
                    if (position < commandBuffer.length())
                    {
                        position++;
                        historyMov = 0;
                    }
//                    _input = Input::LEFT;
                    break;
                case 77:
                    if (position > 0)
                    {
                        position--;
                        historyMov = 0;
                    }
//                    _input = Input::RIGHT;
                    break;
                default:
//                    _input = Input::NONE;
                    break;
            }
        }
        else
        {
            lastKey = key;
            if (!acceptCommand) continue;
            historyMov = 0;
            if (key >= 0x20 && key <= 0x7E)
            { // standard character zone
                if (position != 0)
                {
                    commandBuffer.insert(commandBuffer.end() - position, key);
                }
                else
                {
                    commandBuffer.push_back(key);
                }
            }
            else if (key == 0x0D)
            { // enter
                // accept command
                StringUtil::trim(commandBuffer);
                position = 0;
                if (commandBuffer.length() > 0)
                {
                    std::string ac = std::move(commandBuffer);
                    commandBuffer = std::string();
                    history.push_back(ac);
                    return ac;
                }
            }
            else if (key == 0x08)
            { // backspace
                if (position != commandBuffer.length())
                {
                    commandBuffer.erase(commandBuffer.end() - position - 1);
                }
            }
            else if (key == 0x09)
            {
                // auto complete
            }
        }
    }

    return {};
}

InputService::InputService() : commandBuffer()
{
    commandBuffer.reserve(256);
}

void InputService::renderCMD(std::string prompt, Coord start)
{
    Util::setCursorPos(start);
    std::cout << prompt;
    std::cout << commandBuffer;
    Util::moveCursorPos(-position, 0);
}
