//
// Created by epiphyllum on 22/04/14.
//

#pragma once
#ifndef HACKNETOS_INPUTSERVICE_H
#define HACKNETOS_INPUTSERVICE_H

#include <string>
#include <vector>
#include <optional>
#include "CommonType.h"

typedef void AcceptedCommandCallback(std::string cmd);

// Service to process input functions
class InputService
{
    std::string commandBuffer;
    bool acceptCommand = false;
    int position = 0; // length from the END of the commandBuffer Hello wo|rld  -> 3
    char lastKey = '\0';
    int historyMov = 0;
    std::vector<std::string> history;

public:
    InputService();

    std::optional<std::string> tickInput();

    void renderCMD(std::string prompt, Coord start);

    [[nodiscard]] const std::string &getCommandBuffer() const
    {
        return commandBuffer;
    }

    [[nodiscard]] bool isAcceptCommand() const
    {
        return acceptCommand;
    }

    void setAcceptCommand(bool acceptCommand)
    {
        InputService::acceptCommand = acceptCommand;
    }

    [[nodiscard]] char getLastKey() const
    {
        return lastKey;
    }

    [[nodiscard]] const std::vector<std::string> &getHistory() const;

};


#endif //HACKNETOS_INPUTSERVICE_H
