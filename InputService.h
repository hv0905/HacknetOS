//
// Created by epiphyllum on 22/04/14.
//

#pragma once
#ifndef HACKNETOS_INPUTSERVICE_H
#define HACKNETOS_INPUTSERVICE_H

#include <string>
#include <sstream>

// Service to process input functions
class InputService
{
    std::string commandBuffer;
    bool acceptCommand = false;
    int position = 0; // length from the END of the commandBuffer Hello wo|rld  -> 3
    char lastKey = '\0';


public:
    InputService();

    void tickInput();
    void renderCMD(std::string prompt, int x, int y);

    const std::string &getCommandBuffer() const
    {
        return commandBuffer;
    }

    bool isAcceptCommand() const
    {
        return acceptCommand;
    }

    void setAcceptCommand(bool acceptCommand)
    {
        InputService::acceptCommand = acceptCommand;
    }

    char getLastKey() const
    {
        return lastKey;
    }

};


#endif //HACKNETOS_INPUTSERVICE_H
